"""
No need to change anything here!

If all goes well, this should work after you
modify the Add class in miniflow.py.
"""

from miniflow import *

w, x, y, z = Input(), Input(), Input(), Input()

f = Mul(w, x, y, z)

feed_dict = {w: -3, x: 4, y: 5, z: 10}

graph = topological_sort(feed_dict)
output = forward_pass(f, graph)

# should output 19
print("{} * {} * {} * {} = {} (according to miniflow)".format(feed_dict[w], feed_dict[x], feed_dict[y], feed_dict[z], output))

