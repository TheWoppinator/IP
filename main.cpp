#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <cassert>

using namespace std;

double power(double x, int n){
    //pre-condition:
    assert(n >= 0);
    //post-condition: Standard power function multiplies result with a base.
    double result;
    if(n == 0){
        result = 1;
        return result;
    }else{
       result = x * power(x,n-1);
       return result;

    }

}

double power2(double x, int n){
   //pre-condition:
    assert(n >= 0);
    //post-condition: Improved power function which limits the amount of computations.
     double result;
    if(n == 0){
        result = 1;
        return result;
    }else{
        if(n % 2 == 0){
            return power2(x, n/2)* power2(x, n/2);
        }else{
            return x * power2(x, n/2)* power2(x, n/2);
        }
    }

}

bool palindrome1(string text , int i, int j){
    //pre-condition:
    assert(i <= j && i >= 0 && j >= 0 );
    //post-condition: Checks if a word is a palindrome by checking the first and the last char of the word and adjusting the size.
    if(j != i && j != 0 && i != 0){
        return false;
    }
    else{
        if(j - i == 1 || j == i){
            if(text[i] == text[j]){
                return true;
            }
        }
        else{
            if(text[i] == text[j]){
               palindrome1(text, i + 1, j - 1);
        }
            else{
                return false;
            }
    }
}
}

bool palindrome2(string text , int i, int j){
    //pre-condition:
    assert(i <= j && i >= 0 && j >= 0 );
    //post-condition: Checks if a word is a palindrome by checking the first and the last char of the word and adjusting the size. Adjustment made so A == a.
    if(j != i && j != 0 && i != 0){
        return false;
    }
    else{
        text[j] = tolower(text[j]);
        text[i] = tolower(text[i]);
            if(j - i == 1 || j == i){
                if(text[i] == text[j]){
                    return true;
                }
            }
            else{
                if(text[i] == text[j]){
                   palindrome2(text, i + 1, j - 1);
            }
                else{
                    return false;
                }
        }
    }
}

bool palindrome3(string text , int i, int j){
    //pre-condition:
    assert(i <= j && i >= 0 && j >= 0 );
    //post-condition: Checks if a word is a palindrome by checking the first and the last char of the word and adjusting the size.
    //Adjustment made so A == a. Also reading singes are ignored.
    if(j != i && j != 0 && i != 0){
        return false;
    }
    else{
        text[j] = tolower(text[j]);
        text[i] = tolower(text[i]);
        if(!(text[i] >= 97 && text[i] <= 122)){
            i--;
        }
        if(!(text[j] >= 97 && text[j] <= 122)){
            j--;
        }
            if(j - i == 1 || j == i){
                if(text[i] == text[j]){
                    return true;
                }
            }
            else{
                if(text[i] == text[j]){
                   palindrome3(text, i + 1, j - 1);
            }
                else{
                    return false;
                }
        }
    }
}

bool match_chars (string chars, int i, string source, int j){
    if(chars.length() == 0){
        return true;
    }else{
        for(int k = j; k < source.length(); k++){
            for(int l = i; l < chars.length(); l++){
                if(chars[l] == source[k] && chars[0] == chars[l]){
                chars.erase(l,1);
                    if(match_chars(chars, i, source, k+1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
}

int main()
{
    double result1,result2;
    result1 = power(3.5,5);
    result2 = power2(3.5,6);
    cout << "result power1 is : " << result1 << " result power2 is : " <<result2 << '\n' << endl;
    bool palin1, palin2, palin3, palin4, palin5, palin6, palin7, palin8, palin9;
    palin1 = palindrome1 ("otto", 0, 3);
    palin2 = palindrome1 ("Otto", 0, 3);
    palin3 = palindrome1 ("Madam, I'm Adam.", 0, 15);
    palin4 = palindrome2 ("otto", 0, 3);
    palin5 = palindrome2 ("Otto", 0, 3);
    palin6 = palindrome2 ("Madam, I'm Adam.", 0, 15);
    palin7 = palindrome3 ("otto", 0, 3);
    palin8 = palindrome3 ("Otto", 0, 3);
    palin9 = palindrome3 ("Madam, I'm Adam.", 0, 15);
    cout << std::boolalpha << "Palin1 = " << palin1 << " Palin2 = " << palin2 << " Palin3 = " << palin3 << '\n' << endl;
    cout << std::boolalpha << "Palin4 = " << palin4 << " Palin5 = " << palin5 << " Palin6 = " << palin6 << '\n' << endl;
    cout << std::boolalpha << "Palin7 = " << palin7 << " Palin8 = " << palin8 << " Palin9 = " << palin9 << '\n' << endl;
    bool match1,match2,match3;
    match1 = match_chars ("abc", 0, "It is a bag of cards", 0);
    match2 = match_chars ("abc", 0, "It is a bag of books", 0);
    match3 = match_chars ("abc", 0, "It is a classy bag", 0);
    cout << std::boolalpha << "Match1 = " << match1 << " Match2 = " << match2 << " Match3 = " << match3 << '\n' << endl;


}
