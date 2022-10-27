

import networkx as nx
import matplotlib.pyplot as plt

G = nx.DiGraph()

G.add_node("start",subset="1")
G.add_node("2",subset=1)
G.add_node("3",subset=1)
G.add_node("4",subset=1)
G.add_node("5",subset=1)
G.add_node("6",subset=1)
G.add_node("7",subset=1)

for i in range(2,8):
  G.add_edge("start",str(i))
  G.add_edge(str(i),"end")
G.add_node("end",subset=2)

pos =nx.multipartite_layout(G)
nx.draw_networkx(G,node_size=1000,pos=pos)
plt.show()



