# Ground_Tracks
Numerical Methods project
Satellite Orbital Position Determination Software

## Introduction

The Department of Mission Control at the Catalan Space Agency (AEC) requires a software tool that can accurately determine the position of an artificial satellite in its orbital plane. This calculation is based on the numerical solution of Kepler’s equation. The AEC also needs a separate routine for root-finding to be used by their Test and Validation Department, which will be incorporated into their libraries.

## Overview

This routine is designed to combine the speed of the Newton-Raphson method with the robustness of the bisection method. The strategy to achieve this involves starting with two initial points, ‘a’ and ‘b,’ where the function changes sign, performing bisection until the interval’s length is smaller than a predetermined value ‘δ’ (which should be specified by the user), and then switching to the Newton-Raphson method for greater accuracy.

