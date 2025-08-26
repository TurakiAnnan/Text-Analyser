/*Author of program - Turaki Annan

This programs purpose is to take in the file "textAssement" and use it 
to fullfill the requirments of the coursework*/

//Headers
#include <stdio.h>
#include <string.h>

//Line Size
#define SIZE_OF_LINE 10000


//Function prototypes (tells complier it will be defined later)
int wordCounter(FILE *input_file);
int paragraphCounter(FILE *input_file);
int lineCounter(FILE *input_file);
int fileDuplicator(FILE *input_file, FILE *output_file);
int spellChecker(FILE *input_file, FILE *spelling_file);

int main()
{    
    //Opening the files and creates a pointer to the files 
    FILE *input_file = fopen("textAssesment.txt", "r");
    FILE *output_file =  fopen("output.txt","w");
    FILE *spelling_file =  fopen("dictionary.txt","r");

    // calling functions, passing parameters and storing returened variables 
    int wordCount =wordCounter(input_file);
    rewind(input_file);
    int num_of_paragraphs =paragraphCounter(input_file);
    rewind(input_file);
    int counter =lineCounter(input_file);
    rewind(input_file);


    //printing returned values from functions
    printf("Total number of words: %d\n", wordCount);
    printf("Total number of paragraphs: %d\n", num_of_paragraphs);
    printf("Total number of lines: %d\n", counter);

    //Calling of fileDuplicator function
    fileDuplicator(input_file,output_file);
    
    //Lastly closing the files
    fclose(input_file);
    fclose(output_file);
    fclose(spelling_file);
    
    return 0;
}

//Function definitions

//Function for counting the words with the file
int wordCounter(FILE *input_file)
{
    //local variables 
    int wordCount = 0;
    char line [SIZE_OF_LINE];
    char wordCreators[] = " ,.;!?\n\t";

    //While looping till end of text file
    while(fgets(line, SIZE_OF_LINE, input_file) != NULL)
    {
        //tokenising wordCreators (They are being used a delimeters)
        char *token = strtok(line,wordCreators);
        while(token != NULL){
            wordCount++;
            
            token = strtok(NULL,wordCreators);
        }
    } 
    //returning to main
    return wordCount;
}

int paragraphCounter(FILE *input_file)
{
    int num_of_paragraphs = 0;
    char line [SIZE_OF_LINE];

    //While looping till end of text file
    while(fgets(line, SIZE_OF_LINE, input_file) != NULL)
    {
        // Check if first character in the string line is a new line character or not
        if(line[0] != '\n') {
                num_of_paragraphs++;
        }
    } 
    //returning to main
    return num_of_paragraphs;
}

int lineCounter(FILE *input_file)
{
    int counter = 0;
    char line [SIZE_OF_LINE];

    //While looping till end of text file
    while(fgets(line, SIZE_OF_LINE, input_file) != NULL)
    {
        // Incrementally adding to counter everytime the whileloop is repeated 
        counter++;
    }
    //returning to main
    return counter;
}

//Function duplicates the target file "textAssement.txt" to "output.txt"
int fileDuplicator(FILE *input_file,FILE *output_file)
{
    char line [SIZE_OF_LINE];

    //While looping till end of text file
    while(fgets(line, SIZE_OF_LINE, input_file) != NULL)
    {
        fprintf(output_file, "%s", line);
    } 
    
    //closing file using file variable "output_file"
    return 0;
}

//Checks the spelling by splitting seperating the words
int spellChecker(FILE *input_file, FILE *spelling_file){
    
    char line [SIZE_OF_LINE];
    char dictionaryLine [SIZE_OF_LINE];
    char wordCreators[] = " ,.;!?\n\t";
    //While looping till end of text file
    while(fgets(line, SIZE_OF_LINE, input_file) != NULL){
        char *token = strtok(line,wordCreators);
    }
    while(fgets(dictionaryLine, SIZE_OF_LINE, spelling_file) != NULL){
        char *token = strtok(dictionaryLine,wordCreators);
    }
    return 0; 
}