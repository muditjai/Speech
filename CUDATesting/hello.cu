#include <stdio.h>

__device__ void helloCalledFromDevice()
{
	printf("Device fn hello from GPU\n");
}

__global__ void helloFromGPU()
{
	printf("Hello from GPU thread %d\n", threadIdx.x);
	//helloCalledFromDevice();
}
int main()
{
	printf("Hello from CPU\n");
	helloFromGPU<<<2, 5>>>();
	cudaDeviceSynchronize();
}
