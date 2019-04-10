/* Strings as character arrays :- 
	char str[4] = "GfG"; // One extra for string terminator
	//    OR    
	char str[4] = {‘G’, ‘f’, ‘G’, '\0'}; //'\0' is string terminator 
	
	1. Read only string in a shared segment :- 
			char *str  =  "GfG"; 
	2. Dynamically allocated in heap segment :- 
		    char *str; 
            int size = 4; // one extra for ‘\0’
            str = (char *)malloc(sizeof(char)*size); 
            *(str+0) = 'G';  
            *(str+1) = 'f';   
            *(str+2) = 'G';   
            *(str+3) = '\0'; 	
*/ 

//P1 
int main() 
{ 
 char *str;  
 str = "GfG";     /* Stored in read only part of data segment */
 *(str+1) = 'n'; /* Problem:  trying to modify read only memory */
 getchar(); 
 return 0; 
}  

//P2 
int main() 
{ 
 char str[] = "GfG";  /* Stored in stack segment like other auto variables */
 *(str+1) = 'n';   /* No problem: String is now GnG */
 getchar(); 
 return 0; 
}  

//P3 
int main() 
{ 
  int size = 4; 
  
  /* Stored in heap segment like other dynamically allocated things */
  char *str = (char *)malloc(sizeof(char)*size); 
  *(str+0) = 'G';  
  *(str+1) = 'f';   
  *(str+2) = 'G';     
  *(str+3) = '\0';   
  *(str+1) = 'n';  /* No problem: String is now GnG */
   getchar(); 
   return 0; 
}   


//P4 
char *getString() 
{ 
  char *str = "GfG"; /* Stored in read only part of shared segment */
  
  /* No problem: remains at address str after getString() returns*/
  return str;   
}      
int main() 
{ 
  printf("%s", getString());   
  getchar(); 
  return 0; 
} 

//P5
char *getString() 
{ 
  int size = 4; 
  char *str = (char *)malloc(sizeof(char)*size); /*Stored in heap segment*/
  *(str+0) = 'G';  
  *(str+1) = 'f';   
  *(str+2) = 'G'; 
  *(str+3) = '\0';   
    
  /* No problem: string remains at str after getString() returns */    
  return str;   
}      
int main() 
{ 
  printf("%s", getString());   
  getchar(); 
  return 0; 
} 

//P6 
char *getString() 
{ 
  char str[] = "GfG"; /* Stored in stack segment */
  
  /* Problem: string may not be present after getSting() returns */
  return str;  
}      
int main() 
{ 
  printf("%s", getString());   
  getchar(); 
  return 0; 
}  

//P7 

// C++ program to demonstrate various function string class 
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    // various constructor of string class 
  
    // initialization by raw string 
    string str1("first string"); 
  
    // initialization by another string 
    string str2(str1); 
  
    // initialization by character with number of occurence 
    string str3(5, '#'); 
  
    // initialization by part of another string 
    string str4(str1, 6, 6); //    from 6th index (second parameter) 
                             // 6 characters (third parameter) 
  
    // initialization by part of another string : iteartor version 
    string str5(str2.begin(), str2.begin() + 5); 
  
    cout << str1 << endl; 
    cout << str2 << endl; 
    cout << str3 << endl; 
    cout << str4 << endl; 
    cout << str5 << endl; 
  
    //  assignment operator 
    string str6 = str4; 
  
    // clear function deletes all character from string 
    str4.clear(); 
  
    //  both size() and length() return length of string and 
    //  they work as synonyms 
    int len = str6.length(); // Same as "len = str6.size();" 
  
    cout << "Length of string is : " << len << endl; 
  
    // a particular character can be accessed using at / 
    // [] operator 
    char ch = str6.at(2); //  Same as "ch = str6[2];" 
  
  
    cout << "third character of string is : " << ch << endl; 
  
    //  front return first character and back returns last charcter 
    //  of string 
  
    char ch_f = str6.front();  // Same as "ch_f = str6[0];" 
    char ch_b = str6.back();   // Same as below 
                               // "ch_b = str6[str6.length() - 1];" 
  
    cout << "First char is : " << ch_f << ", Last char is : "
         << ch_b << endl; 
  
    // c_str returns null terminated char array version of string 
    const char* charstr = str6.c_str(); 
    printf("%s\n", charstr); 
  
    // append add the argument string at the end 
    str6.append(" extension"); 
    //  same as str6 += " extension" 
  
    // another version of append, which appends part of other 
    // string 
    str4.append(str6, 0, 6);  // at 0th position 6 character 
  
    cout << str6 << endl; 
    cout << str4 << endl; 
  
    //  find returns index where pattern is found. 
    //  If pattern is not there it returns predefined 
    //  constant npos whose value is -1 
  
    if (str6.find(str4) != string::npos) 
        cout << "str4 found in str6 at " << str6.find(str4) 
             << " pos" << endl; 
    else
        cout << "str4 not found in str6" << endl; 
  
    //  substr(a, b) function returns a substring of b length 
    //  starting from index a 
    cout << str6.substr(7, 3) << endl; 
  
    //  if second argument is not passed, string till end is 
    // taken as substring 
    cout << str6.substr(7) << endl; 
  
    //  erase(a, b) deletes b characters at index a 
    str6.erase(7, 4); 
    cout << str6 << endl; 
  
    //  iterator version of erase 
    str6.erase(str6.begin() + 5, str6.end() - 3); 
    cout << str6 << endl; 
  
    str6 = "This is a examples"; 
  
    //  replace(a, b, str)  replaces b characters from a index by str 
    str6.replace(2, 7, "ese are test"); 
  
    cout << str6 << endl; 
  
    return 0; 
} 
/* OutPut of above Program :-  
	first string
    first string
    #####
    string
    first
    Length of string is : 6
    third character of string is : r
    First char is : s, Last char is : g
    string
    string extension
    string
    str4 found in str6 at 0 pos
    ext
    extension
    string nsion
    strinion
    These are test examples
*/ 

/* IMP:-  
		We can concat a string to another string by += or by append(), but += is slightly slower than append() 
		because each time + is called a new string (creation of new buffer) is made which is returned that is a 
		bit overhead in case of many append operation. 
*/  

// C++ program to demonstrate uses of some string function 
#include <bits/stdc++.h> 
using namespace std; 
  
// this function returns floating point part of a number-string 
string returnFloatingPart(string str) 
{ 
    int pos = str.find("."); 
    if (pos == string::npos) 
        return ""; 
    else
        return str.substr(pos + 1); 
} 
  
// this function checks whether string contains all digit or not 
bool containsOnlyDigit(string str) 
{ 
    int l = str.length(); 
    for (int i = 0; i < l; i++) 
    { 
        if (str.at(i) < '0' || str.at(i) > '9') 
            return false; 
    } 
    //  if we reach here all character are digits 
    return true; 
} 
  
// this function replaces all single space by %20 
// Used in URLS 
string replaceBlankWith20(string str) 
{ 
    string replaceby = "%20"; 
    int n = 0; 
  
    // loop till all space are replaced 
    while ((n = str.find(" ", n)) != string::npos ) 
    { 
        str.replace(n, 1, replaceby); 
        n += replaceby.length(); 
    } 
    return str; 
} 
  
// driver function to check above methods 
int main() 
{ 
    string fnum = "23.342"; 
    cout << "Floating part is : " << returnFloatingPart(fnum)  
         << endl; 
  
    string num = "3452"; 
    if (containsOnlyDigit(num)) 
        cout << "string contains only digit" << endl; 
  
    string urlex = "google com in"; 
    cout << replaceBlankWith20(urlex) << endl; 
  
    return 0;       
}   

/* Output of above Program :- 
	      Floating part is : 342
          string contains only digit
          google%20com%20in 
*/ 
