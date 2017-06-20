#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

void swap(int *x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1),j;
    for(j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int diff(int x,int y)
{
    if(x>y)
        return x-y;
    return y-x;
}

int main(int argc, char *argv[])
{
    int N,i;
    int *tables,*shelves;
    long long time=0;
    char input[10],output[10];
    FILE *fp,*fp1;

    MessageBox(0,"Kriti Agarwal : \tCSE (CC) \t2010644\nKanika Arora : \tCSE (B) \t2010369\nDivyam Panwar : \tCSE (B) \t2010341","Developers' Information",MB_OK);
    printf("Enter name of input file : ");
    gets(input);

    fp=fopen(input,"r");
    if(fp==NULL){
        MessageBox(0,"Input file does not exist","Error Message",MB_OK);
        return 0;
    }

    printf("Enter name of the output file : ");
    gets(output);

    fp1=fopen(output,"w");

    if(feof(fp)){
        MessageBox(0,"Input File is empty","Error Message",MB_OK);
        return 0;
    }

    if(!fscanf(fp,"%d",&N)){
        MessageBox(0,"Invalid Number of test cases","Error Message",MB_OK);
        return 0;
    }

    tables = (int*) malloc(sizeof(int)*N);
    shelves = (int*) malloc(sizeof(int)*N);

    for(i=0;i<N;i++){
        if(feof(fp)){
            MessageBox(0,"No more inputs available","Error Message",MB_OK);
            return 0;
        }
        if(!fscanf(fp,"%d",&tables[i])){
            MessageBox(0,"Invalid input","Error Message",MB_OK);
            return 0;
        }
    }
    for(i=0;i<N;i++){
        if(feof(fp)){
            MessageBox(0,"No more inputs available","Error Message",MB_OK);
            return 0;
        }
        if(!fscanf(fp,"%d",&shelves[i])){
            MessageBox(0,"Invalid Input","Error Message",MB_OK);
            return 0;
        }

    }

    quickSort(tables,0,N-1);
    quickSort(shelves,0,N-1);

    for(i=0;i<N;i++)
    {
        time+=diff(tables[i],shelves[i]);
    }

    fprintf(fp1,"Minimum Time = %lld",time);
    MessageBox(0,"Go to the output file to check the output","Instruction: ",MB_OK);
    fclose(fp);
    fclose(fp1);

    return 0;
}
