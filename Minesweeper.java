import java.io.*;

public class Minesweeper{
	char [][] a = new char[100][100];;
	int [][] f = new int[100][100];
	int dr[] = {0 , 1 , -1 , 0 , 1 , -1 , 1 , -1 };
	int dc[]  ={1 , 1 , 1 , -1 , -1, 1, 0 , 0 };
	int n,m,p;
	public static void main(String args[]) throws IOException{
		Minesweeper obj1 = new Minesweeper();
		System.out.println("Hello world");
		BufferedReader br  = new BufferedReader(new InputStreamReader(System.in)) ;
		System.out.println("Enter N");
		obj1.n = Integer.parseInt(br.readLine());
		System.out.println("Enter M");
		obj1.m = Integer.parseInt(br.readLine());
		System.out.println("Enter P");
		obj1.p = Integer.parseInt(br.readLine());
		for(int i=1;i<=obj1.n;i++){
			for(int j=1;j<=obj1.m;j++){
				obj1.a[i][j] = (char)Integer.parseInt(br.readLine());
				
			}
		}
		for(int i=1;i<=obj1.n; i++){
			for(int j=1;j<=obj1.m;j++){
				if(obj1.a[i][j] == '*'){
					for(int k=0;i<8;i++){
						obj1.f[i+obj1.dr[k]][j+obj1.dc[k]] ++;
					}
				}
			}
		}
		for(int i=1;i<=obj1.n;i++){
			for(int j=1;j<=obj1.m;j++){
				System.out.print(obj1.f[i][j]);
				
			}
			System.out.print("\n");
		}
		
	}
}
