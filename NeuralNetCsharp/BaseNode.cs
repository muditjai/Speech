using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeuralNetCsharp
{
    abstract class BaseNode<T> : INode<T>
    {
        protected string name;
        protected HashSet<INode<T>> inputNodes;
        protected HashSet<INode<T>> outputNodes;

        public string Name
        {
            get
            {
                return this.name;
            }
        }

        protected BaseNode(string name)
        {
            this.name = name;
            inputNodes = new HashSet<INode<T>>();
            outputNodes = new HashSet<INode<T>>();
        }

        public bool AttachInput(INode<T> inputNode)
        {
            inputNodes.Add(inputNode);
            return true;
        }

        public bool AttachOutput(INode<T> outputNode)
        {
            outputNodes.Add(outputNode);
            return true;
        }

        public abstract Task<T> ExecuteBackProp();
        public abstract Task<T> ExecuteForwardProp();
    }
}
