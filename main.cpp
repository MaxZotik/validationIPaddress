#include <iostream>

bool pointCorrect(std::string str){
    char ch = '.';
    int point = 0;

    for(int i = 0; i < str.length(); i++){

        if(str[i] == ch){
            point ++;
        }else if(str[i] < '0' || str[i] > '9'){
            return false;
        }

        if(str[0] == ch || str[str.length() - 1] == ch || str[i] == ch && str[i + 1] == ch){
            return false;
        }
    }

    if(point != 3){
        return false;
    }
    return true;
}

int strIndex(std::string str){


    for(int i = 0; i < str.length(); i++){
        if(str[i] == '.'){
            return i;
        }
    }
    return -1;
}

std::string substrEnd(std::string str, int index){
    std::string strResult;

    for(int i = index; i < str.length(); i++){
        strResult += str[i];
    }

    return strResult;
}

std::string substrStart(std::string str, int index){
    std::string strResult;

    for(int i = 0; i < index; i++){
        strResult += str[i];
    }

    return strResult;
}

bool valueValidation(std::string str){

    if(str.size() > 3){
        return false;
    }

    if(str.size() == 1){
        return true;
    }

    for(int i = 0; i < str.length(); i++){
        if(str.size() == 2 && str[0] == '0'){
            return false;
        }

        if(str.size() == 3 && str[0] == '0' || str[1] == '0'){
            return false;
        }
    }
    return true;
}

bool validationIP(std::string str){

    std::string strTemp = str;


    if(!pointCorrect(str)){
        return false;
    }

    for(int i = 0; i <= 3; i ++){
        if(!valueValidation(substrStart(strTemp, strIndex(strTemp)))){
            return false;
        }
        strTemp = substrEnd(strTemp, strIndex(strTemp) + 1);
    }

    return true;
}

int main() {
    std::string ipCorrect = "127.0.255.1";
    std::string ipIncorrect = "90.256.258.033";
    
    std::cout << validationIP(ipCorrect) << std::endl;
}
