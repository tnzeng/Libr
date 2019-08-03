#ifndef __COMMAND_FLAGS_HPP__
#define __COMMAND_FLAGS_HPP__

#include<vector>
#include<string>
#include<algorithm>

class Flags{
	private:
		std::vector<std::string> flags;
		std::vector<int> flag_arg_count;

	public:
		Flags(){
			std::vector<std::string> f;
			flags = f;
			std::vector<int> fac;
			flag_arg_count = fac;
		}

		Flags(std::vector<std::string> f, std::vector<int> fac){
			flags = f;
			flag_arg_count = fac;
		}

		void add_flag(std::string flag, int arg_count){
			flags.push_back(flag);
			flag_arg_count.push_back(arg_count);
		}

		std::vector<std::string> read_flag(int flag_index, int argc, char** argv){
			std::vector<std::string> args;
			for (int i = 1; i < argc; i++){
				if (flags[flag_index].compare(argv[i]) == 0){
					if (flag_arg_count[flag_index] == -1){
						int j = 0;
						std::string curr;
						while (i + 1 + j < argc){
							curr.assign(argv[i + 1 + j]);
							if (flags.end() != find(flags.begin(), flags.end(), curr)){
								return args;
							} else {
								args.push_back(curr);
							}
							j++;
						}
					} else {
						for (int j = 0; j < flag_arg_count[flag_index]; j++){
							if (i + 1 + j >= argc){
								args.clear();
								return args;
							}
							std::string curr (argv[i + 1 + j]);
							if (flags.end() != find(flags.begin(), flags.end(), curr)){
								args.clear();
								return args;
							} else {
								args.push_back(curr);
							}
						}
					}
				}
			}

			return args;
		}

		std::vector<std::vector<std::string>> read_flags(int argc, char** argv){
			std::vector<std::vector<std::string>> list_args;
			for (unsigned int i = 0; i < flags.size(); i++)
				list_args.push_back(read_flag(i, argc, argv));
			return list_args;
		}

		void print_flags(){
			for (unsigned int i = 0; i < flags.size(); i++)
				std::cout << flags[i] << " ";
			std::cout << std::endl;
		}

};

#endif
