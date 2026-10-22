namespace Esercizio3;
using Esercizio1;

public class UnitTest1
{
    [Fact]
    public void Test1()
    {
        int count = 0;
        IEnumerable<int> source()
        {
            count++;
            yield return 0;
            yield return 1;
            yield return 2;
            yield return 3;
            yield return 4;
        }
        
        var result = source().Slice(2);
        Assert.Equal(0, count);
    }

    [Fact]
    public void Test2()
    {
        int count = 0;
        IEnumerable<int> source()
        {
            count++;
            yield return 0;
            yield return 1;
            yield return 2;
            yield return 3;
            yield return 4;
        }
        
        var result = source().Slice(2).ToList();
        Assert.Equal(1, count);
    }
}
