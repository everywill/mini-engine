# mini-engine
A ECS based game engine, another project of mini-series.

A game engine can be divided to two main parts: one is responsible for game logic(maintain states of the game), the other is for visual rendering.

ECS(Entity, Component and System) is a architecture widely adopted by the industry. Its essence is the organization of data, switching from SoA(Structure of Array) to AoS(Array of Structure). It's counterintuitive and it's gain performance bonus when the scene goes complex.

Rendering is one of the systems mentioned above. It's another big topic to render scenes realistic in real-time. But mini-engine just focus on cross-platfoem rendering, yet another mature technology nowadays.