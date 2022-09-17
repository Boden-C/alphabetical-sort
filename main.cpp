#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using std::string;

void countingSort(std::vector<string> &array, int length, size_t characterAt){
    std::unordered_map<string, int> codeFor = {
      {" ",0},{"-",0},{"'",0},{"À",1},{"ā",1},{"Ă",1},{"ă",1},{"á",1},{"æ",1},{"Æ",1},{"à",1},{"a",1},{"A",1},{"Ä",1},{"Å",1},{"å",1},{"ä",1},{"â",1},{"b",2},{"B",2},{"c",3},{"C",3},{"Ç",3},{"ç",3},{"d",4},{"D",4},{"e",5},{"E",5},{"ê",5},{"ë",5},{"è",5},{"é",5},{"È",5},{"É",5},{"Ê",5},{"Ë",5},{"f",6},{"F",6},{"g",7},{"G",7},{"h",8},{"H",8},{"i",9},{"I",9},{"¡",9},{"Ì",9},{"Í",9},{"Î",9},{"Ï",9},{"ï",9},{"î",9},{"ì",9},{"j",10},{"J",10},{"k",11},{"K",11},{"l",12},{"L",12},{"m",13},{"M",13},{"n",14},{"N",14},{"ñ",14},{"Ñ",14},{"o",15},{"O",15},{"ô",15},{"ö",15},{"ò",15},{"ó",15},{"Ò",15},{"Ó",15},{"Ô",15},{"Õ",15},{"Ö",15},{"p",16},{"P",16},{"q",17},{"Q",17},{"r",18},{"R",18},{"s",19},{"S",19},{"t",20},{"T",20},{"U",21},{"u",21},{"ü",21},{"û",21},{"v",22},{"V",22},{"w",23},{"W",23},{"x",24},{"X",24},{"y",25},{"Y",25},{"Ÿ",25},{"ý",25},{"z",26},{"Z",26}
    };

    std::vector<string> newArray(length);
    std::vector<int> arrayOfCount(27, 0);
    std::vector<int> indexes(length);
    
    for (int i = 0; i < length; i++){ //counts each unique character code
        int index = characterAt < array[i].size() ? (codeFor.find(string(1,array[i][characterAt])) == codeFor.end() ? 0 : codeFor.at(string(1,array[i][characterAt]))) : 0;
	arrayOfCount[index]++;
	indexes[i] = index;
    }
    for (int i = 1; i < 26; i++){ //finds index
        arrayOfCount[i] += arrayOfCount[i - 1];
    }
    
    for (int i = length - 1; i >= 0; i--){ //creates new array using new index
	if (characterAt < array[i].size()) {
	    int index = indexes[length-1-i];
	    newArray[arrayOfCount[index]-1] = array[i];
	    arrayOfCount[index]--;
	} else {
	    newArray[arrayOfCount[0]-1] = array[i];
	    arrayOfCount[0]--;
	}
    }
    for (int i = 0; i < length; i++){ //outputs new array to old array
        array[i] = newArray[i];
    }
}

void radixSort(std::vector<string> &unsortedArray, int length){
    size_t max = unsortedArray[0].size();
    for (int i = 1; i < length; i++){
        if (unsortedArray[i].size()>max)
            max = unsortedArray[i].size();
    } //get number of most characters
    for (size_t characterAt = max; characterAt > 0; characterAt--){ //goes backwards to sort last character to first
      countingSort(unsortedArray, length, characterAt - 1);
    }
}

int main(void) {
    std::vector<string> vector;
    
    for (string line; getline(std::cin, line);) {
        vector.push_back(line);
    }    
    radixSort(vector, vector.size());
    for (size_t i = 0; i < vector.size(); i++) {
        std::cout << vector[i].c_str() << std::endl;
    }
    return 0;
}
