#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>

std::vector<int> getarray(const char* filename);
std::tuple<int, int, int> findtargets(std::vector<int> numbers, int target);

int main(int argc, char **argv){


std::tuple<int, int, int> answers = findtargets(getarray("input.txt"), 2020); 
std::cout<< "answers:"<<(std::get<0>(answers) * std::get<1>(answers)*std::get<2>(answers))<<"\n";


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

std::tuple<int, int, int> findtargets(std::vector<int> numbers, int target){
	int num1;
	int num2;
	int num3;
	bool finished = false;
	std::vector<int>::iterator found;
	for(auto& it : numbers){
		for(auto&it2: numbers){
		found = std::find(numbers.begin(), numbers.end(), (target-it-it2));
		if( found != numbers.end()){
			num1 = it;
			num2 = it2;
			num3 = *found;
		}
		else{
			continue;
		}
		if(finished){
			continue;
		}
	}

	}
	std::tuple<int,int, int> answer(num1,num2, num3);
	return answer;

}