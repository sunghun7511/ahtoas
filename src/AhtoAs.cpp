#include "AhtoAs.hpp"

int main(int argc, char * argv[]){

    vector<string> args(argv, argv + argc);
    GenOptions opt;

    parse_options(args, opt);

    Parser parser(&opt);
    parser.start_parse();

    if(opt.is_debug_mode()){
        print_ir(parser.get_ir_code());
    }

    CodeGenerator code_gen(parser.get_ir_code());

    if(opt.is_out_to_file()){
        std::ofstream file;

        file.open(opt.get_output_file()->c_str());

        code_gen.generate_code(file);
    }else{
        code_gen.generate_code(cout);
    }

    return 0;
}

const void parse_options(const vector<string>& args, GenOptions& options){
    if(args.size() > 1){
        for(auto arg = args.begin()+1; arg != args.end(); ++arg){
            if(!arg->compare("--help")){
                help(args[0]);
            }else if(!arg->compare("--input")
                        || !arg->compare("-i")){
                if(++arg == args.end())
                    error_exit("Invaild arguments..");
                options.set_input_file(*arg);
            }else if(!arg->compare("--output")
                        || !arg->compare("-o")){
                if(++arg == args.end())
                    error_exit("Invaild arguments..");
                options.set_output_file(*arg);
            }else if(!arg->compare("--code")
                        || !arg->compare("-c")){
                if(++arg == args.end())
                    error_exit("Invaild arguments..");
                options.set_source(*arg);
            }else if(!arg->compare("--debug")
                        || !arg->compare("-d")){
                options.set_debug_mode(true);
            }
        }
    }else{
        usage(args[0]);
    }

    if(!options.has_input_file() && !options.has_source()){
        error_exit("No input to compile.");
    }else if(options.has_input_file() && options.has_source()){
        error_exit("Please input just one source.");
    }

    if(options.is_debug_mode()){
        if(options.has_input_file()){
            cout << "Input file : " << *options.get_input_file() << "\n";
        }else{
            cout << "No input file\n";
        }
        
        if(options.is_out_to_file()){
            cout << "Output file : " << *options.get_output_file() << "\n";
        }else{
            cout << "No output file\n";
        }
        
        if(options.has_source()){
            cout << "Source code : " << *options.get_source() << "\n";
        }else{
            cout << "No code\n";
        }
    }
    
    return;
}

const void usage(const string& cmdline){
    cout
        << "Usage : " << "\n"
        << "        " << cmdline << " [-i source_file] [Options]\n"
        << "        " << cmdline << " [-c source] [Options]\n"
        << "        " << cmdline << " [--help]\n";
    std::exit(EXIT_SUCCESS);
}

const void help(const string& cmdline){
    cout
        << "Usage : " << "\n"
        << "        " << cmdline << " [-i source_file] [Options]\n"
        << "        " << cmdline << " [-c source] [Options]\n"
        << "        " << cmdline << " [--help]\n"
        << "\n"
        << "Convert Ahee to Assembly\n"
        << "\n"
        << "    --help              show help\n"
        << " -i --input FILE        source input file\n"
        << " -o --output FILE       output file\n"
        << " -d --debug             debug mode\n"
        << " -c --code              compile from string\n"
        << "\n"
        << "Developer : SHGroup(sunghun7511@naver.com)\n"
        << "Github : https://github.com/sunghun7511/ahtoas\n";
    std::exit(EXIT_SUCCESS);
}