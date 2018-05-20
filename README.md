# Page-Replacement-Algorithms
In a computer operating system that uses paging for virtual memory management, page replacement algorithms decide which memory pages to page out, sometimes called swap out, or write to disk, when a page of memory needs to be allocated. Page replacement happens when a requested page is not in memory (page fault) and a free page cannot be used to satisfy the allocation, either because there are none, or because the number of free pages is lower than some threshold.

When the page that was selected for replacement and paged out is referenced again it has to be paged in (read in from disk), and this involves waiting for I/O completion. This determines the quality of the page replacement algorithm: the less time waiting for page-ins, the better the algorithm. A page replacement algorithm looks at the limited information about accesses to the pages provided by hardware, and tries to guess which pages should be replaced to minimize the total number of page misses, while balancing this with the costs (primary storage and processor time) of the algorithm itself.

The page replacing problem is a typical online problem from the competitive analysis perspective in the sense that the optimal deterministic algorithm is known.

The algorithms chosen to be implement in this program were <b>FIFO (First In First Out), OTM (Optimal) and LRU (Least Recent Used)</b> algorithms. Those are the classic ones.

You can read more about page replacement and each one of its algorithms in wikipedia. <a href="https://en.wikipedia.org/wiki/Page_replacement_algorithm">Page replacement algorithm - Wikipedia</a>. 

# How to use it!

- The compilation of the file is as simple as it follows:
Go straight to the root of the project using the terminal and type the following: <br />
'<b>cmake CMakeLists.txt && make</b>' . (with no quotation marks) 

- Make sure you have cmake pre-installed (Version 3.4 or above). <a href="https://cmake.org/download/">Cmake Download Webpage</a>.
- In order to run the program properly, you must add a file named "input.txt" at the root of the program folder, containing the size of your frame table and and the string of referenced pages in the following format:

   4 <br />
   1 <br />
   2 <br />
   3 <br />
   4 <br />
   1 <br />
   2 <br />
   5 <br />
   1 <br />
   2 <br />
   3 <br />
   4 <br />
   5 <br />
   
- By using this input you will get a output, containg all the information of the number of page fault according to each of the used algorithms:

  FIFO 10 <br />
  OTM 6 <br />
  LRU 8 <br />
  
  [Algorithm] [Number Of Page Faults] 
