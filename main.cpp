
/******************************//******************************
                      Letter_Frequency_CPP

***************************************************************/

#include <iostream>
#include <fstream>
#include <unordered_map>

int main(int argc, char *argv[])
{

if(argc != 2) {
    std::cerr << argv[0] << ": Wrong number of arguments" << std::endl 
	      << argv[0] << ": Usage: " << " file name " 
	      << std::endl;
    return 0;
  }
    
    //data variables
    std::unordered_map<char, int> letter_frequency;
    std::string file_name;
    std::ifstream file_in;
    


//open the file
file_name = argv[1];
file_in.open(file_name);


    
    if (!file_in.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

//do the dew
    char c;
    int count {0};
    while (file_in >> c) {
    count++;
        if (std::isalpha(c)) {
            letter_frequency[std::toupper(c)]++;
        }
    }

    file_in.close();

   if(letter_frequency.size() == 26)
   {
   std::cout << "All leters of the English alphabet are present ";
   std::cout << std::endl;
   }
   
   std::cout << "There are " << count << " letters in this file" << std::endl;
   
    for (const auto& freq : letter_frequency) {
        std::cout << "Letter " << freq.first 
        	  << " appears " << freq.second
        	  << " times." 
        	  << "\t" << " ratio :" << " " << (freq.second/26)
        	  << std::endl;
    }



    return 0;
}
