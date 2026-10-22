using Esercizio1;

namespace Esercizio3;

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

        var result = source().Windowed(2);
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

        var result = source().Windowed(2).ToList();
        Assert.Equal(1, count);
    }

    [Fact]
    public void Test3()
    {
        
        IEnumerable<int> source()
        {
            int i = 0;
            while(true)
                yield return i++;
        }

        var result = source().Windowed(3).Take(4).ToList();
        Assert.Equal(new[]{0,1,2}, result[0]);
        Assert.Equal(new[]{1,2,3}, result[1]);
        Assert.Equal(new[]{2,3,4}, result[2]);
        Assert.Equal(new[]{3,4,5}, result[3]);
    }
}
