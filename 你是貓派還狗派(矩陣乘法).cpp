void InputMatrix(int N, int M, int A[MAXN][MAXN])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			std::cin>>A[i][j];
		}
	}
	return;
}

void PrintMatrix(int N, int M, int A[MAXN][MAXN])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			std::cout << A[i][j] << (j + 1 == M ? '\n' : '\t');
		}
	}
	return;
}

void MatrixMultiplication(int N, int K, int M, int A[MAXN][MAXN], int B[MAXN][MAXN], int C[MAXN][MAXN])
{
	for(int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				C[i][j]=0;
				for (int k = 0; k < K; ++k)
				{
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
	return;
}

void DecryptImage(int N, int M, int A[MAXN][MAXN], int B[MAXN][MAXN], int C[MAXN][MAXN], int S[MAXN][MAXN])
{
	int tmp[MAXN][MAXN];
	MatrixMultiplication(N,N,M,A,C,tmp);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			tmp[i][j] = tmp[i][j]%251;
		}
	}
	MatrixMultiplication(N,M,M,tmp,B,S);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			S[i][j] = S[i][j]%251;
		}
	}
	return;
}
