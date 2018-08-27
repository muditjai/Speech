using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeuralNetCsharp
{
    interface INodeOutput<T>
    {
        T outputVal { get; }
    }

    interface INodeInput<T>
    {
        IEnumerable<T> outputVal { get; }
    }
}
