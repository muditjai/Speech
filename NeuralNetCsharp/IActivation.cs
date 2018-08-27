namespace NeuralNetCsharp
{
    internal interface IActivation<T>
    {
        T applyActivation(T input);
    }
}