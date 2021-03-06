# Полиморфизъм

## Задача
Да се реализира полиморфична йерархия от класове представляващи
двуизмерни фигури и да се реализира следната функционалност:
* По ключова дума **contains** и подадена точка да се извеждат фигурите които съдържат дадената точка
 > contains 2.5 2.5
 
 > 1 - Rectangle 0.0 4.0
 
 > 5 - Circle 0 15
 
 ---
 
 > contains 100 100
 
 > No shapes contain this point.
 

* По ключова дума **absolute** и пореден номер на фигура **[1, броя]** да се изведат нейните абсолютни координати (ако е в група се прилага транслацията)
 > absolute 1
 
 > Rectangle 0.0 4.0

* По ключова дума **area** и дадено число, да се извежда лицето на поредната фигура, при липса на число да се изведат лицата на всички фигури като списък.
 > area 1
 
 > 1 - Rectangle - 25
 
 ---
 > area
 
 > 1 - Rectangle - 25
 
 > 2 - Circle - 9.68
 
 > ...
 
*  По ключова дума **perimeter** и дадено число, да се извежда лицето на поредната фигура, при липса на число да се изведат лицата на всички фигури като списък.
 > perimeter 1
 
 > 1 - Rectangle - 20
 
 ---
 > perimeter
 
 > 1 - Rectangle - 20
 
 > 2 - Circle - 10.23
 
 > ...
 

Фигурите които ще трябва да имплементирате са :

1. **Окръжност** - зададена по координати център и дължина на радиуса.
    >**circle 3.0 7.5 3.15**
2. **Триъгълник** - зададен по координати на 3-те върха.
    >**triangle 1.0 1.0 2.0 1.0 1.0 2.0**
3. **Правоъгълник** - зададен по 2 срещуположни върха, като неговите
страни са успоредни на координатните оси.
    >**rect -1.0 -1.0 2.0 2.0**
4. **Група** - това представлява последователност от фигури - **окръжност,
триъгълник или правоъгълник** които са транслирани с вектор. Например с транслационен вектор (5.0,-7.3): 
    
    >**group in 5.0 -7.3**
     
    >**rect -1.0 -1.0 2.0 2.0**
    
    >**rect -1.0 -1.0 2.0 2.0**
    
    >**rect -1.0 -1.0 2.0 2.0**
    
    > **group out**
    
---
    
Входа на програмата ще се чете от текстов файл, като всяка фигура ще бъде
на отделен ред. 

Изключение прави групата, като тя ще се дефинира като
започва от **group in** и завършва на **group out**, и всички редове между тези двата
са фигури принадлежащи в тази група. 

Файлът винаги ще е правилен и не се
налага да проверявате за коректност, няма да има случай на група която се
съдържа в друга група.

За заявка на фигура на индекс 3 се извежда **rect 1.0 -2.0 4.0 1.0** като
координатите са получени при сбора на координатите на правоъгълника и
транслиращият вектор от групата.

Погледнете прикачения файл **shapes.txt**

Author: Ivan Filipov - [**GitHub**](https://github.com/IvanFilipov/)
