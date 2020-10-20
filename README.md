# Задание №3

В соответствии с заданием был разработан класс "Логический элемент".

### Состояние класса

> Логический элемент определяется последовательностью описателей клемм. Описатель клеммы содержит информацию о типе клеммы (входная или выходная), количестве соединений (входная клемма может иметь не больше 1 соединения, а выходная клемма – не больше 3 соединений) и состоянии сигнала - значение уровня 0, 1 или Х (неопределенное состояние).

В данном варианте класса логический элемент задаётся статическим массивом описателей клемм. При реализации методов класса используется перегрузка операторов.

Описатель клеммы реализуется как структура *Clamp*, содержащая тип клеммы *t*, количество соединений *ports* и состояние сигнала *signal*.

Состояние класса определяется следующим образом:
 * максимальное количество описателей клемм - *SZ*;
 * количество клемм в данный момент - *num*;
 * и массив структур описателей клемм *clmps[SZ]*.

### Методы класса

Для работы с классом были реализованы следующие методы:
 * Конструкторы:
     * Пустой конструктор, инициализирующий логический элемент как инвертор с одной входной и выходной клеммой без соединений с неопределённым состоянием сигнала;
     * Конструктор, инициализирующий логический элемент количеством входных и выходных клемм без соединений с неопределённым состоянием сигнала;
     * Конструктор, инициализирующий логический элемент единственным числом - количеством всех клемм *N*, при этом количество входных клемм определяется целочисленным делением *N* пополам.
 * Деструктор в данной реализации класса не является необходимым;
 * Два вспомогательных метода:
     * Метод для проверки корректности состояний сигнала каждой клеммы *corrSignal*;
     * Метод для проверки корректности данного номера клеммы *corrNumber*.
 * Ввод состояний сигналов всех клемм с помощью перегруженного оператора *>>*, также используется метод *corrSignal*;
 * Вывод информации обо всех клеммах логического элемента в виде псевдографического рисунка, при этом все входные клеммы отображаются слева, выходные - справа, соответственно. Количество соединений отображается на стыке символов _*_, а состояние сигнала - рядом с количеством соединений. Метод реализуется с помощью перегруженного оператора *<<*;
 * Ввод информации о состоянии сигнала клеммы по её номеру, используется метод *corrNumber* и перегрузка оператора *()*;
 * Получение информации о состоянии сигнала клеммы по её номеру, используется метод *corrNumber* и перегрузка оператора *[]*;
 * Увеличение количества соединений клеммы на единицу по её номеру - метод *connect*, используется метод *corrNumber*;
 * Уменьшение количества соединений клеммы на единицу по её номеру - метод *disconnect*, также используется метод *corrNumber*, при этом если количество соединений станет равным нулю, состояние сигнала клеммы изменится на неопределённое *X*;
 * Добавление клеммы к логическому элементу с помощью перегруженного оператора *+=*.

### Тестирующая прикладная программа

При работе тестирующей программы логический элемент инициализируется как инвертор. Для того, чтобы проверить работу программы, достаточно запустить исполняемый файл *main.exe*, который находится в папке *src/*.