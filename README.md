# iFUB algorithm
Presenting linear O(M) Diamter finding algorithm with worst case O(m * n). This is simply a C++ implementation of this iFUB algorithm.

<h3>iFUB Algorithm Psedocode</h3>
<pre>
Input: A graph G, a node u, a lower bound l for the diameter, and an integer k
Output: A value M such that D − M ≤ k
i ← ecc(u);
lb ← max{ecc(u), l};
ub ← 2ecc(u);
while ub − lb > k do
  if max{lb, Bi(u)} > 2(i − 1) then
    return max{lb, Bi(u)};
  else
    lb ← max{lb, Bi(u)};
    ub ← 2(i − 1);
  end
i ← i − 1;
end
return lb;
</pre>

<h3>4-SWEEP Algorithm Psedocode</h3>
<pre>
Input: A graph G
Output: A lower bound for the diameter of G and a node with (hopefully) low eccentricity
r1 ← random node of G or node with the highest degree;
a1 ← argmaxv∈V d(r1, v);
b1 ← argmaxv∈V d(a1, v);
r2 ← the node in the middle of the path between a1 and b1;
a2 ← argmaxv∈V d(r2, v);
b2 ← argmaxv∈V d(a2, v);
u ← the node in the middle of the path between a2 and b2;
lowerb ← max{ecc(a1), ecc(a2)};
return lowerb and u;
</pre>

<h3>iFUB Termination Theorem.</h3> For any 1 ≤ i < ecc(u) and 1 ≤ k < i, and for any x ∈ Fi−k(u) such that ecc(x) > 2(i − 1), there exists yx ∈ Fj(u) such that d(x, yx) = ecc(x) with j ≥ i.

<h3>Observation 1. </h3> for any x and y in V such that x ∈ Fi(u) or y ∈ Fi(u), we have that d(x, y) ≤ Bi(u): indeed, d(x, y) ≤ min{ecc(x), ecc(y)} ≤ Bi(u). 
<h3>Observation 2. </h3>for any 1 ≤ i, j ≤ ecc(u) and for any x ∈ Fi(u) and y ∈ Fj(u), we have d(x, y) ≤ i + j ≤ 2 max{i, j}.

<h3>Proof.</h3> Since ecc(x) > 2(i − 1), then there exists yx whose distance from x is equal to ecc(x) and, hence, greater than 2(i − 1). If yx was in Fj(u) with j < i, then from the previous observation it would follow that d(x, yx) ≤ 2 max{i − k, j} ≤ 2 max{i − k, i − 1} = 2(i − 1), which is a contradiction. Hence, yx must be in Fj(u) with j ≥ i. 

# NOT COMPLETED
Accept help from Anyone. Simply push it.

# Cite
Pilu Crescenzi, Roberto Grossi, Michel Habib, Leonardo Lanzi, Andrea Marino,
On computing the diameter of real-world undirected graphs,
Theoretical Computer Science,
Volume 514,
2013,
Pages 84-95,
ISSN 0304-3975,
https://doi.org/10.1016/j.tcs.2012.09.018.
(https://www.sciencedirect.com/science/article/pii/S0304397512008687)
Abstract: We propose a new algorithm for the classical problem of computing the diameter of undirected unweighted graphs, namely, the maximum distance among all the pairs of nodes, where the distance of a pair of nodes is the number of edges contained in the shortest path connecting these two nodes. Although its worst-case complexity is O(nm) time, where n is the number of nodes and m is the number of edges of the graph, we experimentally show that our algorithm works in O(m) time in practice, requiring few breadth-first searches to complete its task on almost 200 real-world graphs.
Keywords: Breadth-first search; Diameter; Complex network; Experimental analysis
