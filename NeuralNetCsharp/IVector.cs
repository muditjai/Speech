using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeuralNetCsharp
{
    interface IVector<T>
    {
        int Size { get; }
        T[] VectorVals { get; }
        T dot(IVector<T> otherVec);
    }
}
