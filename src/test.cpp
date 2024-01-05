#include <iostream>
#include <unistd.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <functional>
#include <omp.h>
#include <map>
#include <fstream>

#include "cabin.h"

#include "column.h"
#include "types.h"
#include "configure.h"
#include "queryqueue.h"
#include "hybrid_timer.h"
#include "test.h"


void parse_arg(arg_t &arg, int &argc, char** &argv);
void print_arg(const arg_t& arg);

int main(int argc, char* argv[]){
    std::cout << LONGLINE << LONGLINE << std::endl;

    arg_t arg;
    parse_arg(arg, argc, argv);

    std::cout << "[INFO ] Creating column ..." << std::endl;
    auto *column = new Column(arg.size);
    auto *query = new QueryQueue();

    std::cout << "[INFO ] Populating column with random values ..." << std::endl;

#if TEST_TYPE == 0

    WordUnit max = (std::numeric_limits<WordUnit>::max)();

//#define TEST_NDV
#ifdef TEST_NDV
    auto dice = std::bind(std::uniform_int_distribution<WordUnit>( \
                                  0, \
                                  49), \
                          std::default_random_engine(232));
#else
    auto dice = std::bind(std::uniform_int_distribution<WordUnit>( \
                                  std::numeric_limits<WordUnit>::min(), \
                                  std::numeric_limits<WordUnit>::max()), \
                          std::default_random_engine(232));
#endif
#undef TEST_NDV

//#define GEN
#define TRIVIAL

#ifdef TRIVIAL
    for (size_t i = 0; i < arg.size; i++) {
        column->SetTuple(i, dice());
    }
    std::cout << "[INFO ] Finished generating random values ..." << std::endl;

    query->QueryGenerate(column, arg);
#else
#ifdef GEN
    std::string out_datafile_name = "../data/10e9_32_uniform.data";
    std::ofstream out_datafile;
    out_datafile.open(out_datafile_name);
    std::cout << out_datafile_name << std::endl;
    for (size_t i = 0; i < arg.size; i++) {
        /*double tmp1 = dice();
        //WordUnit tmp = llround(tmp1);
        WordUnit tmp = tmp1;*/
        column->SetTuple(i, dice());
        out_datafile << dice() << std::endl;
    }
    out_datafile.close();
    std::cout << "[INFO ] Finished generating values to output data file ..." << std::endl;

    query->QueryGenerate(column, arg);
    std::string out_queryfile_name = "../data/10e9_32_uniform_1001.query";
    std::ofstream out_queryfile;
    out_queryfile.open(out_queryfile_name);
    std::cout << out_queryfile_name << std::endl;
    for (auto i : query->query)
    {
        out_queryfile << i << std::endl;
    }
    out_queryfile.close();
    std::cout << "[INFO ] Finished generating queries to output query file ..." << std::endl;
#else
    std::string in_datafile_name = "../data/10e9_32_uniform.data";
    std::cout << in_datafile_name << std::endl;
    std::ifstream in_datafile;
    in_datafile.open(in_datafile_name);
    if (!in_datafile) {
        std::cout << "file doesn't exist: " << in_datafile_name << std::endl;
        exit(-1);
    }

    if (in_datafile.is_open()) {
        std::string line;
        size_t i = 0;
        while (std::getline(in_datafile, line)) {
            WordUnit value;
            value = std::stoi(line);
            column->SetTuple(i++, value);
        }
        in_datafile.close();
    }
    std::cout << "[INFO ] Finished reading values from input data file ..." << std::endl;

    std::string in_queryfile_name = "../data/10e9_32_uniform_1001.query";
    std::cout << in_queryfile_name << std::endl;
    query->QueryGenerateFromFile_int(in_queryfile_name);
    std::cout << "[INFO ] Finished reading queries from input query file ..." << std::endl;
#endif
#endif
#undef GEN
#elif TEST_TYPE == 1   // zipf integer
    // zipf
    WordUnit max = (std::numeric_limits<WordUnit>::max)();
    std::random_device rd;
    std::mt19937 gen(232);
    double zipf_p = 2.0;
    zipf_distribution<> zipf(max,zipf_p);
    std::cout << "zipf parameter: " << zipf_p << std::endl;

    for (size_t i = 0; i < arg.size; i++) {
        column->SetTuple(i, zipf(gen));
    }

    std::cout << "[INFO ] Finished generating random values ..." << std::endl;

    query->QueryGenerate(column, arg);
#elif TEST_TYPE == 2 // READ DATA & QUERY FROM FILE
    std::string data_file;
    data_file = "/your/data/directory";
    std::string query_file = "/your/query/directory";

    std::ifstream infile;
    infile.open(data_file);

    std::string line;
    int i = 0;
    while (getline(infile,line)){
        WordUnit v;
        v = std::stof(line);    // !!! When changing the dataset, remember to change the function
        column->SetTuple(i, v);
        i++;
    }
    column->num_tuples_ = i;
    std::cout << "num tuple: " << i << std::endl;

    std::cout << "[INFO ] Finished reading values ..." << std::endl;

    query->QueryGenerateFromFile_float(query_file);   // !!! When changing the dataset, remember to change the function
#else
#endif

    if(arg.patch_type == 0) {
        Test<Cabin>(column, query, arg);
    } else if (arg.patch_type == 1){
        TestPatch<Cabin>(column, query, arg);
    } else if(arg.patch_type == 2) {
        TestQuery<Cabin>(column, query, arg);
    } else if(arg.patch_type == 3) {
        auto *wf = new workloadFeature;
        wf->available_memory = arg.available_memory;
        TestQuerySPA(column, query, wf, arg);
    } else {
        exit(EXIT_FAILURE);
    }
    delete column,query;
}


void parse_arg(arg_t &arg, int &argc, char** &argv){
    int c;
    std::string s;
    while((c = getopt(argc, argv, "s:y:r:a:p:m:h")) != -1){
        switch(c){
            case 'h':
                std::cout << "Usage: " << argv[0] << std::endl
                << " [-s <size (the number of data)>]" << std::endl
                << " [-y <selectivity (%)>]" << std::endl
                << " [-r <repeat>]" << std::endl
                << " [-p <patch>]" << std::endl
                << "    [-0 filter with single selectivity ]" << std::endl
                << "    [-1 filter with all selectivities ]" << std::endl
                << "    [-2 filter with the given quries ]" << std::endl
                << "    [-3 filter with the given quries and space budget ]" << std::endl
                << " [-a <algorithm>]" << std::endl
                << "    [-0 cabin]" << std::endl
                << " [-m <available memory (GB)>]" << std::endl
                << std::endl;
                exit(0);
            case 's':
                arg.size = atoi(optarg);
                break;
            case 'y':
                arg.selectivity = atof(optarg);
                break;
            case 'r':
                arg.repeat = atoi(optarg);
                break;
            case 'p':
                arg.patch_type = atoi(optarg);
                break;
            case 'm':
                arg.available_memory = atof(optarg);
                break;
            case 'a':
                arg.algo = static_cast<algorithm>(atoi(optarg));
                break;
        }
    }
    
    print_arg(arg);   
}

void print_arg(const arg_t& arg){
    std::cout
    << "[INFO ] table size = "   << arg.size         << std::endl
    << "[INFO ] selectivity = "  << arg.selectivity  << std::endl
    << "[INFO ] repeat = "       << arg.repeat       << std::endl
    << "[INFO ] patch = "        << arg.patch_type   << std::endl
    << "[INFO ] available memory = "      << arg.available_memory   << std::endl;
    switch (arg.algo) {
        case cabin:
            std::cout << "[INFO ] algo = " << "cabin"   << std::endl;
            break;
        default:
            std::cout << "no corresponding algorithm~~~"   << std::endl;
            break;
    }
}