# Иструкции за remote упражнения с **git**

За целта на тези упражнения ще ползваме git като всички участници ще добавят работите си в едно общо git repository.

Понеже повечето от вас не знаят как се работи с git, това ще са инструкции и начини на работа за по-нататъчни упражнения.

### 1. Изтеглете си и инсталирайте git
Git e безплатен и може да се свали [тук][git]. За macOS и Linux има инструкции в сайта.

### 2. Направете си github акаунт и си създайте repository
Тази стъпка трябва да е тривиална за всички понеже предполагам, че имате опит със създаването на акаунти, в който и да е сайт. Този не се различава от другите.\
След като сте си направили акаунт отивате в профила си (от иконката горе в дясно) -> Your repositories -> New (за създаване на ново repository). Задайте си име на repository-то и го оставете публично. След като сте създали repository-то ще ви отведе на заглавната страница, където в началото ще имате инструкции за инициализация на локалното reository.
![img](https://i.imgur.com/1DtJApg.png)
Оттук ще следваме първия параграф и по-долу ще е обяснено подробно какво правят командите на всяка стъпка.

### 3. Инициализиране на локалното repository
За да си инициализираме локално repository трябва да:
1. да си направим нова папка.
2. да отворим Git Bash в тази папка. Това става с десен бутон -> Git Bash Here ![img](https://i.imgur.com/ErMHvNl.png)
3. да напишем командата `git init`

### 4. Стъпки за бъдеща работа
От тук нататък вече може да добавяме и работим над файловете, които имаме в папката. Като за начало нека си създадем празен файл, който да се казва README.md (това прави и първия ред от инструкциите в github). След това стъпките за процедиране са:
1. (optional) командата `git status` ни показва статуса ни в repository-то. Вслучая ни командата трябва да покаже нещо подобно на: ![img](https://i.imgur.com/v1tp4ii.png)\
Това означава че git знае че сме направили нов файл който все още не сме добавили в repository-то.
2. За да го добавим към файловете, които ще са в следващата промяна, използваме командата `git add <име на файл/папка>` или `git add .` за вички файлове, които са нови (оцветените в червено). След изпълнението може да кажем `git status` и ще се покаже нещо подобно на: ![img](https://i.imgur.com/RZbw7SE.png)\
Което означава че вече сме добавили този файл да е част от следващата промяна която ще направим. Тази стъпка може да я повтаряме множество пъти, за да добавим още файлове ако пожелаем.
3. За да направим **промяна** или **commit** (**commit** == **промяна**) използваме командата `git commit -m "<commit message>"`. Това създава нова **commit** като ни казва какво сме променили: ![img](https://i.imgur.com/ZbAts7f.png)\
**Note:** ако правите тази съпка за първи път ще ви излезне нещо подобно на: ![img](https://i.imgur.com/FBScP96.png)\
което означава, че не сте си настроили user name и email за гит. Просто въведете командите, които съобщението ви казва `git config --global ..` с името и email-a ви от github.
4. (само веднъж) Ако до сега не сте изпълнявали тази стъпка до сега ще трябва да въведете командата `git remote add <адреса на github repository-то>`. Този адрес може да се вземе от началната страница на repository-то ви в github (на първата снимка -> кутийката с адреса). 
5. Вече сме направили промяна и трябва да я качим в repository-то в github. За целта трябва да напишем командата `git push`.\
**Note 1:** Ако изпълнявате командата за първи път в това repository ще ви покаже грешка ![img](https://i.imgur.com/AcN2E5w.png)\
Просто въвеждате командата която ви показва (това е еквивалентно на последната команда от github инструкциите).\
**Note 2:** Ако командата изведе грешка най-вероятно трябва да си свалим всички последни промени преди да качим нашите. Това става с `git pull`.
След изпълнението му можем отново да кажем `git push`.

От тук на сетне за всяка следваща промяна, която искате да запазите ще трябва да минете през стъпка **4.** за да ги запазите и качите.

[git]: https://git-scm.com/
[github_repo]: https://github.com/ceko98/OOP-pract-remote-repo