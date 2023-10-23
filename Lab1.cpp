#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream dosyaOku("dosya.txt");
  string satir = "";

  if ( dosyaOku.is_open() ){

    while ( getline(dosyaOku, satir) ){
      cout << satir << endl;
    }
    
    dosyaOku.close();
  }
  
  return 0;
}
