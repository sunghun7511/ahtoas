#include "AhtoAs.hpp"

int main(int argc, char * argv[]){
    
    std::tr1::shared_ptr<GenOptions> opt(new GenOptions());

    if(!opt){
        error_exit("Allocate error on GenOptions");
    }

    parse_options(argc, argv, opt);

    std::tr1::shared_ptr<Parser> parser(new Parser(opt));
    parser->start_parse();

    if(opt->is_debug_mode()){
        print_ir(parser->get_ir_code());
    }

    std::tr1::shared_ptr<CodeGenerator> code_gen(new CodeGenerator(parser->get_ir_code()));

    if(opt->is_out_to_file()){
        std::ofstream file;

        file.open(opt->get_output_file());

        code_gen->generate_code(file);
    }else{
        code_gen->generate_code(std::cout);
    }

    return 0;
}

const void parse_options(const int argc, const char * const argv[], const std::tr1::shared_ptr<GenOptions> options){
    if(argc > 1){
        
    }else{
        usage(argv[0]);
    }
    
    if(!options->has_input_file() && !options->get_source().empty()){
        error_exit("No input to compile.");
    }else if(options->has_input_file() && options->get_source().empty()){
        error_exit("Please input just one source.");
    }
    return;
}

const void usage(const char * const cmdline){
    std::cout
        << "Usage : " << "\n"
        << "        " << cmdline << " [-s source_file] [Options]\n"
        << "        " << cmdline << " [-c source] [Options]\n"
        << "        " << cmdline << " [--help]\n";
    std::exit(EXIT_SUCCESS);
}

const void help(const char * const cmdline){
    std::cout
        << "Usage : " << "\n"
        << "        " << cmdline << " [-s source_file] [Options]\n"
        << "        " << cmdline << " [-c source] [Options]\n"
        << "        " << cmdline << " [--help]\n"
        << "\n"
        << "Convert Ahee to Assembly\n"
        << "\n"
        << "    --help              show help\n"
        << " -i --input FILE        source input file\n"
        << " -o --output FILE       output file\n"
        << " -d --debug             debug mode\n"
        << "\n"
        << "Developer : SHGroup(sunghun7511@naver.com)\n"
        << "Github : https://github.com/sunghun7511/ahtoas\n";
    std::exit(EXIT_SUCCESS);
}