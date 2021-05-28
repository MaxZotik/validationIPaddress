#include <iostream>
#include <string>

//correct number of points
bool pointCorrect(std::string str){
    char ch = '.';
    int point = 0;

    if(str[0] == ch || str[str.length() - 1] == ch){
        return false;
    }

    for(int i = 0; i < str.length() - 1; i++){

        if(str[i] == ch){
            point ++;
        }else if(str[i] < '0' || str[i] > '9'){
            return false;
        }

        if(str[i] == ch && str[i + 1] == ch){
            return false;
        }
    }

    return point == 3;
}

//get index dot
int strIndexPoint(std::string str){

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '.'){
            return i;
        }
    }

    return -1;
}

//trim the string from the end
std::string substrEnd(std::string str, int index){
    std::string strResult;

    for(int i = index; i < str.length(); i++){
        strResult += str[i];
    }

    return strResult;
}

//trim the line from the beginning
std::string substrStart(std::string str, int index){
    std::string strResult;

    for(int i = 0; i < index; i++){
        strResult += str[i];
    }

    return strResult;
}

//check for the number of characters and the presence of zeros at the beginning
bool valueValidation(std::string str){

    if(str.size() > 3){
        return false;
    }

    if(str.size() == 1){
        return true;
    }

    if(str.size() > 1 && str[0] == '0'){
        return false;
    }

    int num = std::stoi(str);

    if(num < 0 || num > 255){
        return false;
    }

    return true;
}

//check the IP address
bool validationIP(std::string str){

    std::string strTemp = str;
    int index;

    if(!pointCorrect(str)){
        return false;
    }

    for(int i = 0; i < 4; i ++){
        index = strIndexPoint(strTemp);

        if(index != - 1){
            if(!valueValidation(substrStart(strTemp, index))){
                return false;
            }
        }else{
            if(!valueValidation(strTemp)){
                return false;
            }
        }

        strTemp = substrEnd(strTemp, strIndexPoint(strTemp) + 1);
    }

    return true;
}

int main() {
    std::string ipString;

    std::cout << "Enter PI address!" << std::endl;
    std::cin >> ipString;

    if(validationIP(ipString)){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }


}
