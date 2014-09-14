#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


/*
 * Remove a char from position pos,
 * then merges string back together.
 */
void removeChar(char * str, int len, int pos){
  char * src = (str + pos + 1);
  memcpy(str + pos, src, strlen(src));
  str[len - 1] = '\0';
}

/*
 * Finds max character
 */
char maximum(char * array, int size){
  
  int curr = 0;
  char max = '\0';
  
  for(curr = 0; curr < size; curr++){
    if(strcmp((const char *)(array  + curr), &max) > 0){
      max = array[curr];
    }
  }
  return max;
}

/*
 * Completes counting sort on the array
 */
void countingSort(char* array, int size){
  
  int curr = 0;
  char max = maximum(array, size);
  char * counting_array = calloc(max - 97, sizeof(char)); // Fills array w/ max
  
  for(curr = 0; curr < size; curr ++){
    counting_array[array[curr]]++;
  }
  
  int num = 0;
  curr = 0;
  
  while(curr <= size){
    while(counting_array[num] > 0){
      array[curr] = num;
      counting_array[num]--;
      curr++;
      if(curr > size){ break; }
    }
    num++;
  }
  
  // Check for duplicates
  for(curr = 1; curr < size; curr++){
    if(array[curr] == array[curr - 1]){
      removeChar(array, size, curr);
      size--;
      curr--;
    }
  }
  
  free(counting_array);
  array[size] = '\0';
}

int main() {
  
  int i, j, k; // iterators
  int lines, compare, len;
  size_t maxSize = 1024;
  int flag = 0;
  
  scanf("%d", &lines);
  
  char * rocks = (char*)malloc(maxSize);
  char * gems;
  
  // Grab new rock
  for(i = 0; i < lines; i++){
    
    scanf("%s", rocks);
    
    // Initialize Gem finder
    if(i == 0){
      
      len = strlen(rocks);
      gems = (char*)malloc(len);
      strcpy(gems, rocks);
      countingSort(gems, len);
      len = strlen(gems);
      
    }else{
      
      // Loop to check gems
      for(k = 0; k < len; k++){
        flag = 0;
        // Loop to check rocks
        for(j = 0; j < strlen(rocks); j++){
          compare = gems[k] ^ rocks[j];
          if(compare == 0){
            flag = 1;
            break;
          }
        }
        if(flag == 0){
          removeChar(gems, len--, k);
          k--;
        }
      }
    }
    if(len == 0){ break; }
  }
  printf("%d\n", len);
  free(gems);
  return 0;
}