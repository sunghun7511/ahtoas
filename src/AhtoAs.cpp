#include "AhtoAs.hpp"

int main(int argc, char * argv[]){
    
    std::shared_ptr<GenOptions> opt(new GenOptions());

    if(!opt){
        error_exit("Allocate error on GenOptions");
    }

    parse_options(argc, argv, opt);

    std::shared_ptr<IRCode> ir(new IRCode());
    parse(opt, ir);

    if(opt->is_debug_mode){
        print_ir(ir);
    }

    if(opt->is_out_to_file()){
        std::ofstream file(opt->get_output_file);

        generate_code(ir, file);
    }else{
        generate_code(ir, std::cout);
    }

    return 0;
}

void parse_options(const int argc, const char * const argv[], const std::shared_ptr<GenOptions> options){
    if(argc > 1){
        
    }else{
        usage(argv[0]);
    }
    
    if(!options->has_input_file && !options->get_source){
        error_exit("");
    }else if(options->has_input_file && !options->get_source){

    }
    return;
}

void usage(const char * const cmdline){
    std::cout
        << "Usage : " << "\n"
        << "        " << cmdline << " [-s source_file] [Options]"
        << "        " << cmdline << " [-c source] [Options]";
    std::exit(EXIT_SUCCESS);
}

void help(const char * const cmdline){
    std::cout
        << "Usage : " << "\n"
        << "        " << cmdline << " [-s source_file] [Options]"
        << "        " << cmdline << " [-c source] [Options]"
        << "\n"
        << "Convert Ahee to Assembly\n"
        << "\n"
        << "        --help              Show help\n";
    std::exit(EXIT_SUCCESS);
}