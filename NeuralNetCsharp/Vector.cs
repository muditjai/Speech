using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeuralNetCsharp
{
    abstract class BasicMath<T>
    {
        public abstract T Add(T a, T b);
        public abstract T Minus(T a, T b);
        public abstract T Multiply(T a, T b);
        public abstract T Divide(T a, T b);
    }

    class BasicMatchInt : BasicMath<int>
    {
        public override int Add(int a, int b)
        {
            return a + b;
        }

        public override int Divide(int a, int b)
        {
            return a / b;
        }

        public override int Minus(int a, int b)
        {
            return a - b;
        }

        public override int Multiply(int a, int b)
        {
            return a * b;
        }
    }

    class BasicMatchfloat : BasicMath<float>
    {
        public override float Add(float a, float b)
        {
            return a + b;
        }

        public override float Divide(float a, float b)
        {
            return a / b;
        }

        public override float Minus(float a, float b)
        {
            return a - b;
        }

        public override float Multiply(float a, float b)
        {
            return a * b;
        }
    }

    class Vector<T> : IVector<T>// where M: BasicMath<T>, new()
    {
        //private M mathOps = new M();

        private T[] vectorVals;

        public Vector(T[] vectorVals)
        {
            this.vectorVals = vectorVals;
        }

        public int Size
        {
            get
            {
                return this.vectorVals.Length;
            }
        }

        public T[] VectorVals
        {
            get
            {
                return this.vectorVals;
            }
        }

        public T dot(IVector<T> otherVec)
        {
            T sum = default(T);
            for(int i = 0; i < Size; i++)
            {
                //sum = mathOps.Add(sum, mathOps.Multiply(this.vectorVals[i], otherVec.VectorVals[i]));
            }

            return sum;
        }
    }
}
