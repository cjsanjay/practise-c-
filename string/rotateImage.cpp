#include<iostream>
#include<sstream>
using namespace std;

int **rotateImage1(int **image,int height,int width){
	int **imagenew;
	imagenew=new int* [height];
	for(int i=0;i<height;i++){
		imagenew[i]=new int[width];
	}
	for(int i=0,k=0;i<width;i++,k++){
		for(int j=height-1,m=0;j>=0;j--,m++){
			imagenew[k][m]=image[j][i];
		}
	}	
	return imagenew;
}


int rotateImage2(int **image,int height,int width){
	int temp;
	for(int i=0;i<height;i++){
		for (int j=i;j<width;j++){
				temp=image[i][j];
				image[i][j]=image[j][i];
				image[j][i]=temp;
		}
	}
	
	for(int i=0;i<height;i++){
		for(int j=0,k=width-1;j<width/2;j++,k--){
			temp=image[i][j];
			image[i][j]=image[i][k];
			image[i][k]=temp;
		}
	}
}

int main(int argc,char *argv[]){
	int **image;
	int height,width;
	stringstream check,check1;
	check << argv[1] <<' '<<argv[2];
	check >> height >> width;
	
	cout << "Height:"<<height <<"width:"<<width<<endl;
	image=new int* [height];
	for(int i=0;i<height;i++){
		image[i]=new int[width];
	}
	int count=1;
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			image[i][j]=count;
			count++;
		}
	}
	rotateImage2(image,height,width);
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			cout <<image[i][j] <<" ";
		}
		cout <<"\n";
	}
	delete image;
	return 0;
}
