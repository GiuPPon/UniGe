namespace Esercizio1;

public static class Class1
{
    public static IEnumerable<T[]> Slice<T> (this IEnumerable<T> source, int size)
    {
        ArgumentOutOfRangeException.ThrowIfNegativeOrZero(size);
        return Iterator();

        IEnumerable<T[]> Iterator()
        {
            var queue = new Queue<T>(size);
            foreach(var item in source)
            {
                queue.Enqueue(item);
                if(queue.Count == size)
                {
                    yield return queue.ToArray();
                    queue.Clear();
                }
            }

            if (queue.Count > 0)
                yield return queue.ToArray();
        }
        
    }
}
