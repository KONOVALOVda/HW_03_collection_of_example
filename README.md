# HW_03_collection_of_example

Коллекция примеров использования API ядра Linux для работы со структурами данных и алгоритмами.

Каждый модуль — это маленький пример, который показывает, как использовать разные структуры данных в ядре Linux.
После загрузки модулей сообщения можно посмотреть в dmesg.

ex_list.ko — пример работы со связным списком (list_head):
добавление, обход и удаление элементов.

ex_queue.ko — пример работы с очередью (kfifo):
запись в очередь и чтение из неё.

ex_bitmap.ko — пример работы с битовыми картами (bitmap):
установка и проверка отдельных бит.

ex_rb_tree.ko — пример работы с красно-чёрным деревом (rbtree):
вставка узлов и обход дерева.

ex_bin_search.ko — пример бинарного поиска (bsearch):
сортировка массива и поиск элемента.

# СОБРАТЬ 

#sudo apt install linux-headers-$(uname -r) -y

git clone https://github.com/KONOVALOVda/HW_03_collection_of_example.git

cd HW_03_collection_of_example

make

# Как проверить

Пример на модуле ex_list:

sudo insmod ex_list.ko       # загрузить модуль


dmesg | tail -n 20           # посмотреть вывод


sudo rmmod ex_list           # выгрузить модуль


-------------------------------------------------------

sudo insmod ex_queue.ko

dmesg | tail -n 20

sudo rmmod ex_queue

======================
sudo insmod ex_bitmap.ko
dmesg | tail -n 20
sudo rmmod ex_bitmap

=====================

sudo insmod ex_rb_tree.ko
dmesg | tail -n 20
sudo rmmod ex_rb_tree

======================

sudo insmod ex_bin_search.ko
dmesg | tail -n 20
sudo rmmod ex_bin_search
