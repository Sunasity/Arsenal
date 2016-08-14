# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
import numpy as np

A = np.zeros((64, 27))
B = np.zeros((27, 224))
C = np.zeros((64, 224))
A = np.loadtxt("A_64x27.dat")
B = np.loadtxt("B_27x224.dat")
C = A.dot(B)
C = np.reshape(C, (-1, 1))
np.savetxt("C_py_64_224.dat", C, fmt = '%d')