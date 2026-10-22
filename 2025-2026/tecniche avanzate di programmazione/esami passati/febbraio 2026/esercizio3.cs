namespace Esercizio3;

using System.IO.Compression;
using Moq;

public interface ITextOutput {
    void Write(string s);
}
public class MyPrinter {
    private readonly ITextOutput _output;
    public MyPrinter(ITextOutput output) => _output = output;
    public void PrintFirstN<T>(IEnumerable<T> source, int count) {
        foreach(var el in source.Take(count))
            _output.Write(el?.ToString() ?? "boh");
    }
}
public class UnitTest1
{
    [Fact]
    public void Test1()
    {
        var moq = new Mock<ITextOutput>();
        var service = new MyPrinter(moq.Object);
        var source = new List<int>{1,2,3};
        service.PrintFirstN(source,2);

        moq.Verify(c => c.Write("2"), Times.Once);
        moq.Verify(c => c.Write(It.IsAny<string>()), Times.Exactly(2));
    }
}
