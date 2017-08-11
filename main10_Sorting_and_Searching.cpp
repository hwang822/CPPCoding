#include <cppcoding.h>



void swap(int arr[], int left, int right){

    int tem = arr[left];

    arr[left]  = arr[right];

    arr[right] = tem;

}



int partition(int arr[], int left, int right){

    int pivot = arr[(left+right)/2]; //pick pivot point

    while(left <= right){

        while(arr[left] < pivot) left++;

        while(arr[right] > pivot) right--;



        if(left<=right){

            swap(arr, left, right);

            left++;

            right--;

        }

    }

    return left;

}



void quickSort(int arr[], int left, int right){

    int index = partition(arr, left, right);

    if (left < index -1){

        quickSort(arr, left, index-1);

    }

    if(index < right)

    {

        quickSort(arr, index, right);

    }

}



int binarySearch(int a[], int x){

  int low = 0;

  int high = sizeof(a)/4 -1;

  int mid;



  while(low <= high){

      mid = (low + high)/2;

      if(a[mid] < x){

          low = mid + 1;

      } else if (a[mid] > x) {

          high = mid -1;

      } else {

          return mid;

      }

  }

  return -1;



}



int binarySearchRescursive(int a[], int x, int low, int high){

    if(low > high) return -1;



    int mid = (low + high) /2;

    if (a[mid] < x){

        return binarySearchRescursive(a, x, mid+1, high);

    } else if ( a[mid] > x ){

        return binarySearchRescursive(a, x, low, mid-1);

    } else {

        return mid;

    }

}



//*************************

//10.1 Merage sorted A and Sorted B at A.



void merge(int a[], int b[], int lasta, int lastb){



    int last = lasta + lastb + 1;



    while(lastb>=0){

        if((lasta>=0)&&(a[lasta]>b[lastb])){

           a[last] = a[lasta];

           lasta--;

        }

        else

        {

            a[last] = b[lastb];

            lastb--;

        }

        last--;

    }

}



//10.2 regourp strings in arrays in anarams in together.

// char a[] = {"abcd", "ab", "bcda", "ba");



#include <bits/stdc++.h>

/*

string sortCHars(string s){

    const char *content = s.c_str();



    int n = sizeof(content)/sizeof(content[0]);

    sort(content, content+n);

    std::string cpp_style = new std::string(content, 0, n);

    return new cpp_style;

}



#include <unordered_map>



void sort(string array[]){



    std::unordered_map<std::string, std::string> mapList = new std::unordered_map<std::string, std::string> <string, string>();

    for(string s : arrya){

        string key = sortChars(s);

        mapList.insert(key, s);

    }



    int index = 0;

    for(string key : maplist.keySet()){

        ArrayList<string> list = maplist.at(key);

        for(string t : list)

        {

            array[lindex] = t;

            index++;

        }

    }

}

*/



//10.3 search in rotated sorted int array.

// it is not sorted array any more, it is hard to use binary search.



//10.4 Sorted Search. No size



//10.5 Sparse Search string array with empty string



int search(string strings[], string str, int first, int last)

{

    if(first>last) return -1;

    int mid = (last + first)/2;



    if(strings[mid]==""){

        int left = mid-1;

        int right = mid+1;

        while(true){

            if((left<first)&&(right>last)){

                return -1;

            } else if (right <= last && strings[right]!="") {

                mid = right;

                break;

            } else if (left >= first && strings[left]!="") {

                mid = left;

                break;

            }

            right++;

            left--;

        }

    }





    if(strings[mid].compare(str)==0)

        return mid;

    else if(strings[mid].compare(str)<0) //search right

        return search(strings, str, mid+1, last);

    else //search left

        return search(strings, str, first, mid-1);

}





//10.6 for big file. Divid big file to chucks in memory limit and sort each chuck. Then merage chuck



//1o.7 Missing int


//10.9 mxn array sorted at rows an cols, find elem

#include <stdio.h>
const int M = 3;
const int N = 3;





//*************************
//10.1 Merage sorted A and Sorted B at A.


//From C99, C language supports variable sized arrays to be passed simply by specifying the variable dimensions

bool findFlement(int matrix[M][N], int elem){

    int row = 0;
    int cols = sizeof(matrix[0])/sizeof(int);
    int rows = sizeof(matrix)/sizeof(int);
    int col = cols -1;
    while((row<rows)&&(col>=0)){
        if(matrix[row][col]==elem){
            return true;
        } else if (matrix[row][col]>elem){ //first check if right bigger item of row > elem , no for next row
            col--;
        } else {
            row++;
        }
    }


    return false;
}


int main10(){

/*

    int data[] = {3, 5, 2, 5, 3, 6, 7, -2, 90, 2, -9, 6};



    quickSort(data, 0, sizeof(data)/4);



    int datasorted[] = {-9, 3, 5, 7, 12, 34, 35, 37, 42, 90, 102, 160};



    int index = binarySearchRescursive(datasorted, 12, 0, sizeof(datasorted)/4);



    if(index>0)

        return 1;



    // 10.1 test

    int a[] = {1, 2, 4, 7, 0, 0, 0 ,0};

    int b[] = {3, 4, 5};

    int lasta = 3;

    int lastb = 2;

    merge(a, b, lasta, lastb);

*/

    // 10.2 test

    string array[] = {"abcd", "ab", "adcb", "ba"};

//    sort(array);



    // 10.3 test

    string balls[] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};

    //int length = sizeof(balls);

    search(balls, "ball", 0, 13);



    return 0;

}
