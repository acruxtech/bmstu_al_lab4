#include <limits>
#include <vector>
#include <iostream>


float mean(const std::vector<float> &seq) {
    float sum { 0.0 };
    for (float item : seq)
        sum += item;
    return sum / seq.size();
}


std::pair<float, float> minMax(const std::vector<float> &seq) {        
    if (seq.empty()) {
        return std::make_pair(
            std::numeric_limits<float>::min(),
            std::numeric_limits<float>::max()
        );
    }

    float min = { std::numeric_limits<float>::max() };
    float max = { std::numeric_limits<float>::min() };

    for (float item : seq) {
        if (item < min) 
            min = item;
        if (item > max)
            max = item;
    }
    return std::make_pair(min,max);
}


int argmax(const std::vector<float> &seq) {
    int max_arg_index = -1;
    int max_item = std::numeric_limits<float>::min();
    for (int i = 0; i < seq.size(); i++) {
        if (seq[i] > max_item) {
            max_item = seq[i];
            max_arg_index = i;
        }
    }
    return max_arg_index;
}


void sort(std::vector<float> &seq) {
    for (int i = 0; i < seq.size() - 1; i++) {
        for (int j = 0; j < seq.size(); j++) {
            if (seq[j] < seq[j + 1]) {
                float t = seq[j];
                seq[j] = seq[j + 1];
                seq[j + 1] = t; 
            }
        }
    }
}


bool remove_first_negative_element(std::vector<int> &vec, int &removed_element) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] < 0) {
            removed_element = vec[i];
            vec.erase(vec.begin() + i);
            return true;
        }
    }
    removed_element = 0;
    return false;
}


std::string replace(const std::string &str, const std::string &old, const std::string &new_string) {
    std::string newString = "";
    size_t pos = 0;
    while (pos < str.size()) {
        size_t found = str.find(old, pos);
        if (found != std::string::npos) {
            newString += str.substr(pos, found - pos);
            newString += new_string;
            pos = found + old.size();
        } else {
            newString += str.substr(pos);
            break;
        }
    }
    return newString;
}


std::vector<std::string> split(const std::string &str, char sep) {
    std::vector<std::string> result;
    std::string temp = "";
    for (char c : str) {
        if (c == sep) {
            if (!temp.empty()) {
                result.push_back(temp);
                temp = "";
            }
        } else {
            temp += c;
        }
    }
    if (!temp.empty()) {
        result.push_back(temp);
    }
    return result;
}


std::string join(const std::vector<std::string> &vec, const std::string &sep) {
    std::string result = "";
    for (int i = 0; i < vec.size(); ++i) {
        result += vec[i];
        if (i < vec.size() - 1) {
            result += sep;
        }
    }
    return result;
}



int main() {
    std::vector<float> seq = {1.2, 13.4, 543.112, 122.112};
    // seq = { };

    // std::cout << mean(seq) << std::endl; 
    
    // std::cout << minMax(seq).first << " " << minMax(seq).second << std::endl;
    
    // std::cout << argmax(seq) << std::endl;

    // for (float item : seq)
    //     std::cout << item << " ";
    // std::cout << std::endl;
    // sort(seq);
    // for (float item : seq)
    //     std::cout << item << " ";
    // std::cout << std::endl;

    // int r;
    // std::vector<int> seq2 = {-12, 134, 543112, 122112};
    // remove_first_negative_element(seq2, r);

    // std::string newString = replace("Can you can a can as a canner can can a can?", "can", "cAN");
    // std::cout << newString;

    // std::vector<std::string> arr = split("Can you can a can as a canner can can a can?", ' ');

    // std::vector<std::string> arr = {"Can", "you", "can", "a", "can", "as", "a", "canner", "can", "can", "a", "can?"};
    // std::string str = join(arr, " ");
    // std::cout << str << std::endl; 

    return 0;
}

