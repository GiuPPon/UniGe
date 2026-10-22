using Esercizio1;

namespace Esercizio3;

public class UnitTest1
{
    [Fact]
    public void Test1()
    {
        int count = 0;
        IEnumerable<int> source() {
            count++;
            yield return 0;
            yield return 1;
            yield return 2;
            yield return 3;
            yield return 4;
        }
        var result = source().TakeThenSkip(2,3);
        Assert.Equal(0, count);
    }

    [Fact]
    public void Test2()
    {
        int count = 0;
        IEnumerable<int> source() {
            count++;
            yield return 0;
            yield return 1;
            yield return 2;
            yield return 3;
            yield return 4;
        }
        var result = source().TakeThenSkip(2,3).ToList();
        Assert.Equal(1, count);
    }

    [Fact]
    public void Test3()
    {
        IEnumerable<int> source() {
            int i = 0;
            while(true)
                yield return i++;
        }
        var result = source().TakeThenSkip(2,3).Take(8).ToList();
        Assert.Equal(new[]{0,1,5,6,10,11,15,16}, result);
    }
}
