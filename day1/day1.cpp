#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>

std::vector<int> getarray(const char* filename);
std::tuple<int, int> findtargets(std::vector<int> numbers, int target);

int main(int argc, char **argv){


std::tuple<int, int> answers = findtargets(getarray("input.txt"), 2020); 
std::cout<< "answers:"<<(std::get<0>(answers) * std::get<1>(answers))<<"\n";


return 0;

}


std::vector<int> getarray(const char* filename){
	std::vector<int> numbers;
	std::ifstream infile(filename);
	int num;
	if(!infile){
		std::cout<< "we broke";
		return numbers;
	}
	while(infile >> num){
		numbers.push_back(num);
	}
	int size = static_cast<int>(numbers.size());
std::cout<<"we out"<<size;
std::sort(numbers.begin(), numbers.end());
return numbers;
}

std::tuple<int, int> findtargets(std::vector<int> numbers, int target){
	int num1;
	int num2;
	std::vector<int>::iterator found;
	for(auto& it : numbers){
		found = std::find(numbers.begin(), numbers.end(), (target-it));
		if( found != numbers.end()){
			num1 = it;
			num2 = *found;
		}
		else{
			continue;
		}

	}
	std::tuple<int,int> answer(num1,num2);
	return answer;

}