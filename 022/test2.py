import os
print(os.path.basename(os.path.realpath(__file__)))
print(os.path.realpath(__file__)[:-11])