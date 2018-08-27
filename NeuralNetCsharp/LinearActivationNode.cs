using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeuralNetCsharp
{
    abstract class LinearActivationNode<T>: BaseNode<T>
    {
        protected IVector<T> linearVector;
        protected IActivation<T> activation;

        public LinearActivationNode(string name) : base(name)
        {
        }

        public async override Task<T> ExecuteForwardProp()
        {
            List<Task<T>> inputFwdPropResults = new List<Task<T>>();
            foreach(var inputNode in this.inputNodes)
            {
                inputFwdPropResults.Add(inputNode.ExecuteForwardProp());
            }

            T[] resultVals = await Task.WhenAll(inputFwdPropResults.ToArray());

            IVector<T> inputVec = new Vector<T>(resultVals);
            /*if (typeof(T) == typeof(int))
            {
                Converter<T, int> c = new Converter<T, int>(input => (int)System.Convert.ChangeType(input, typeof(int)));
                inputVec = new Vector<int, BasicMatchInt>(Array.ConvertAll<T, int>(resultVals, c));
            }
            else if (typeof(T) == typeof(float))
            {
                inputVec = new Vector<float, BasicMatchfloat>(resultVals);
            }*/
                
            

            T dotProduct = this.linearVector.dot(inputVec);
            T outputValue = activation.applyActivation(dotProduct);
            return outputValue;
        }

        public override Task<T> ExecuteBackProp()
        {
            throw new NotImplementedException();
        }
    }
}
