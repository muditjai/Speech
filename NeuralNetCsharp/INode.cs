using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeuralNetCsharp
{
    public interface INode<T>
    {
        string Name { get; }

        bool AttachInput(INode<T> inputNode);
        bool AttachOutput(INode<T> outputNode);
        Task<T> ExecuteForwardProp();
        Task<T> ExecuteBackProp();
    }
}
