void split(char* src, const char* separator, char** dest, int* num) {
     char* pNext;
     int count = 0;
    
     if (src == NULL || strlen(src) == 0) return;
     if (separator == NULL || strlen(separator) == 0) return;
     pNext = strtok(src, separator); 
    
     while(pNext != NULL) {
          *dest++ = pNext;
          ++count;
         pNext = strtok(NULL, separator);
    }  
    
    *num = count;
} 

bool wordPattern(char * pattern, char * str){
    char* voc[1000] = {0};
    int str_len = 0;
    split(str, " ", voc, &str_len);
    
    if(strlen(pattern) != str_len) return false;
        
    for(int i = 0; i < str_len; i++){
        for(int j = i+1; j < str_len; j++){ 
            if(*(pattern+i) == *(pattern+j) && strcmp(voc[i], voc[j]) != 0) 
                return false;
            if(*(pattern+i) != *(pattern+j) && strcmp(voc[i], voc[j]) == 0) 
                return false;
        }
    }
            
    return true;
}
