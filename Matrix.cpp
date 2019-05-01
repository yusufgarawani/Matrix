#include <iostream> 
#include <string> 
#include <sstream> 
#include <algorithm> 

using namespace std;

void add  (int col1,int col2, int row1, int row2, float arr1[100][100], float arr2[100][100], float arr3[100][100]){
            if ( col1 != col2 || row1 != row2) cout << "ERROR";
       else {     cout << "[";
            for (int i =0; i < row1; i++){
                  for (int j=0; j < col1; j++){
                        arr3[i][j] = arr1[i][j] + arr2[i][j]; 
                        cout << arr3[i][j]; 
                        if (j != col1 - 1) cout << " ";
                                                }
                 if ( i != row1 - 1)cout <<";";
            } cout << "]";
       }

}

void subtract (int col1,int col2, int row1, int row2, float arr1[100][100], float arr2[100][100], float arr3[100][100]){
            if ( col1 != col2 || row1 != row2) cout << "ERROR";
      else {      cout << "[";
            for (int i =0; i < row1; i++){
                  for (int j=0; j < col1; j++){
                        arr3[i][j] = arr1[i][j] - arr2[i][j]; 
                        cout << arr3[i][j];
                        if (j != col1 - 1) cout << " ";
                  }
                  if (i != row1 -1) cout << ";";
            }     cout << "]";
      }
}


void multiply (int col1,int col2, int row1, int row2, float arr1[100][100], float arr2[100][100], float arr3[100][100]){
      
      if ( row2 != col1 ) cout << "ERROR";
 else {
       cout << "[";
       for (int r =0; r < row1; ++r)
            for (int c = 0; c < col2; ++c)
                arr3[r][c] = 0;
       for (int r =0; r <row1; ++r)
           {
                  for ( int c = 0; c < col2; ++c)
            {
                  for (int k = 0; k <col1; ++k)
                        arr3[r][c] += arr1[r][k] * arr2[k][c];
                        cout << arr3[r][c]; 
                        if ( c != col2 - 1) cout <<" ";
                  
            }
            if (r != row1 - 1) cout <<";";
            }
            cout <<"]";
            }
}
int main () { 

   string arr1, arr2;
   string arr_1[10000], arr_1_2df[100][100];
   string s, x_1, xs_1;
   int n, cols_1 = 0, rows_1 = 1, y_1, k_1 = 0, r_1 = 0;
   char c = '[';
   float z_1;
   float farr_1[100][100], farr_3[100][100];
   string arr_2[10000], arr_2_2df[100][100];
   string  x_2, xs_2;
   int  cols_2 = 0, rows_2 = 1, y_2, k_2 = 0, r_2 = 0;
   float z_2;
   float farr_2[100][100];
   string operation; 

      
          getline (cin,arr1);
          rows_1 = count(arr1.begin(), arr1.end(), ';');
          rows_1 = rows_1 + 1;
          cols_1 = count(arr1.begin(),arr1.end(), ' ');
          replace( arr1.begin(), arr1.end(), ';', ' ');
          arr1.erase(remove(arr1.begin(),arr1.end(), c), arr1.end());     
                stringstream ssin_1(arr1);
                while (ssin_1.good()){ 
                         ssin_1 >> arr_1[r_1];
                         xs_1 = arr_1[r_1];
                         ++r_1;
                               } 
       
                                cols_1 = (cols_1 + rows_1) / rows_1; 

          getline (cin, operation);
         if (operation != "+"&& (operation != "-" && operation != "*")) cout <<"ERROR";   

          getline (cin,arr2);
          rows_2 = count(arr2.begin(), arr2.end(), ';');
          rows_2 = rows_2 + 1;
          cols_2 = count(arr2.begin(),arr2.end(), ' ');
          replace( arr2.begin(), arr2.end(), ';', ' ');
          arr2.erase(remove(arr2.begin(),arr2.end(), c), arr2.end());
                stringstream ssin_2(arr2);
                while (ssin_2.good()){
                         ssin_2 >> arr_2[r_2];
                         xs_2 = arr_2[r_2];
                                ++r_2;
                                        }
                            cols_2 = (cols_2 + rows_2) / rows_2;

              //Matrix 1 to 2D array
                                                     
                      for (int i =0; i < rows_1; i++) {
                          for (int j =0; j < cols_1; j++){
                                arr_1_2df[i][j] = arr_1[k_1++];
                 }
           }   

                 // Matrix 2 to 2D array

                      for (int i =0; i < rows_2; i++) {
                          for (int j =0; j < cols_2; j++){
                                arr_2_2df[i][j] = arr_2[k_2++];
                 }
           }
                 
              
                  //Matrix 1 to 2D float array
                      
        for (int i = 0; i < rows_1; ++i){
             for (int j =0; j <cols_1; ++j){
                   x_1 = arr_1_2df[i][j];
                   z_1 = atof(x_1.c_str());
                   farr_1[i][j] = z_1;
             }
       }

           //Matrix 2 to 2D float array

        for (int i = 0; i < rows_2; ++i){
             for (int j =0; j <cols_2; ++j){
                   x_2 = arr_2_2df[i][j];
                   z_2 = atof(x_2.c_str());
                   farr_2[i][j] = z_2;
                         }
       }
             
                 if (operation == "+")   add     (cols_1,cols_2, rows_1,rows_2, farr_1, farr_2, farr_3);
                 if (operation == "-") subtract  (cols_1,cols_2, rows_1,rows_2, farr_1, farr_2, farr_3);
                 if (operation == "*") multiply  (cols_1,cols_2, rows_1,rows_2, farr_1, farr_2, farr_3); 
}


