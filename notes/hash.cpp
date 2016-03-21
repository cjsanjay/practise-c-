<b>Algorithmic Complexity</b>
The good news is that only a few function classes tend to occur in the course
of basic algorithm analysis. These suffice to cover almost all the algorithms we will
discuss in this text, and are listed in order of increasing dominance:

	• Constant functions, f (n) = 1 – Such functions might measure the cost of
adding two numbers, printing out “The Star Spangled Banner,” or the growth
realized by functions such as f (n) = min(n, 100). In the big picture, there is
no dependence on the parameter n.
	• Logarithmic functions, f (n) = log n – Logarithmic time-complexity shows up
in algorithms such as binary search. Such functions grow quite slowly as n
gets big, but faster than the constant function (which is standing still, after
all). Logarithms will be discussed in more detail in Section 2.6 (page 46)
	• Linear functions, f (n) = n – Such functions measure the cost of looking at
each item once (or twice, or ten times) in an n-element array, say to identify
the biggest item, the smallest item, or compute the average value.
	•Superlinear functions, f (n) = n lg n – This important class of functions arises
in such algorithms as Quicksort and Mergesort. They grow just a little faster
than linear (see Figure 2.4), just enough to be a different dominance class.
	• Quadratic functions, f (n) = n 2 – Such functions measure the cost of looking
at most or all pairs of items in an n-element universe. This arises in algorithms
such as insertion sort and selection sort.
	• Cubic functions, f (n) = n 3 – Such functions enumerate through all triples of
items in an n-element universe. These also arise in certain dynamic program-
ming algorithms developed in Chapter 8.
	• Exponential functions, f (n) = c n for a given constant c > 1 – Functions like
2 n arise when enumerating all subsets of n items. As we have seen, exponential
algorithms become useless fast, but not as fast as. . .
	• Factorial functions, f (n) = n! – Functions like n! arise when generating all
permutations or orderings of n items.
