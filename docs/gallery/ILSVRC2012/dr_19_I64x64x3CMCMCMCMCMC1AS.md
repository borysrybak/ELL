---
layout: default
title: 64x64x3 Convolutional Neural Network
permalink: /gallery/ILSVRC2012/dr_19_I64x64x3CMCMCMCMCMC1AS
---

[Back to Gallery](/ELL/gallery)

## ILSVRC2012 Classification: 64x64x3 Convolutional Neural Network (52.96% top 1 accuracy, 76.80% top 5 accuracy, 0.16s/frame on Raspberry Pi 3)

<table class="table table-striped table-bordered">
    <tr>
        <td> Download </td>
        <td colspan="3"> <a href="https://github.com/Microsoft/ELL-models/raw/master/models/ILSVRC2012/dr_19_I64x64x3CMCMCMCMCMC1AS/dr_19_I64x64x3CMCMCMCMCMC1AS.ell.zip">dr_19_I64x64x3CMCMCMCMCMC1AS.ell.zip</a></td>
    </tr>
    <tr>
        <td> Accuracy </td>
        <td colspan="3"> ILSVRC2012: 76.80% (Top 5), 52.96% (Top 1) </td>
    </tr>
    <tr>
        <td> Performance </td>
        <td colspan="3"> Raspberry Pi 3 (Raspbian) @ 700MHz: 0.16s/frame </td>
    </tr>
    <tr>
        <td> Uncompressed Size </td>
        <td colspan="3"> 65MB </td>
    </tr>
    <tr>
        <td> Input </td>
        <td colspan="3"> 64 &times; 64 &times; {B,G,R} </td>
    </tr>
    <tr>
        <td> Architecture </td>
        <td>
            <table class="arch-table">
                <tr class="arch-table">
                    <td>Convolution</td>
                    <td>&#8680;&nbsp;64×64×32</td>
                    <td>size=3×3,&nbsp;stride=1,&nbsp;type=float32,&nbsp;activation=leaky&nbsp;relu</td>
                </tr>
                <tr class="arch-table">
                    <td>Pooling</td>
                    <td>&#8680;&nbsp;34×34×32</td>
                    <td>size=2×2,&nbsp;stride=2,&nbsp;operation=max</td>
                </tr>
                <tr class="arch-table">
                    <td>Convolution</td>
                    <td>&#8680;&nbsp;32×32×64</td>
                    <td>size=3×3,&nbsp;stride=1,&nbsp;type=float32,&nbsp;activation=leaky&nbsp;relu</td>
                </tr>
                <tr class="arch-table">
                    <td>Pooling</td>
                    <td>&#8680;&nbsp;18×18×64</td>
                    <td>size=2×2,&nbsp;stride=2,&nbsp;operation=max</td>
                </tr>
                <tr class="arch-table">
                    <td>Convolution</td>
                    <td>&#8680;&nbsp;16×16×128</td>
                    <td>size=3×3,&nbsp;stride=1,&nbsp;type=float32,&nbsp;activation=leaky&nbsp;relu</td>
                </tr>
                <tr class="arch-table">
                    <td>Convolution</td>
                    <td>&#8680;&nbsp;16×16×64</td>
                    <td>size=1×1,&nbsp;stride=1,&nbsp;type=float32,&nbsp;activation=leaky&nbsp;relu</td>
                </tr>
                <tr class="arch-table">
                    <td>Convolution</td>
                    <td>&#8680;&nbsp;16×16×128</td>
                    <td>size=3×3,&nbsp;stride=1,&nbsp;type=float32,&nbsp;activation=leaky&nbsp;relu</td>
                </tr>
                <tr class="arch-table">
                    <td>Pooling</td>
                    <td>&#8680;&nbsp;10×10×128</td>
                    <td>size=2×2,&nbsp;stride=2,&nbsp;operation=max</td>
                </tr>
                <tr class="arch-table">
                    <td>Convolution</td>
                    <td>&#8680;&nbsp;8×8×256</td>
                    <td>size=3×3,&nbsp;stride=1,&nbsp;type=float32,&nbsp;activation=leaky&nbsp;relu</td>
                </tr>
                <tr class="arch-table">
                    <td>Convolution</td>
                    <td>&#8680;&nbsp;8×8×128</td>
                    <td>size=1×1,&nbsp;stride=1,&nbsp;type=float32,&nbsp;activation=leaky&nbsp;relu</td>
                </tr>
                <tr class="arch-table">
                    <td>Convolution</td>
                    <td>&#8680;&nbsp;8×8×256</td>
                    <td>size=3×3,&nbsp;stride=1,&nbsp;type=float32,&nbsp;activation=leaky&nbsp;relu</td>
                </tr>
                <tr class="arch-table">
                    <td>Pooling</td>
                    <td>&#8680;&nbsp;6×6×256</td>
                    <td>size=2×2,&nbsp;stride=2,&nbsp;operation=max</td>
                </tr>
                <tr class="arch-table">
                    <td>Convolution</td>
                    <td>&#8680;&nbsp;4×4×512</td>
                    <td>size=3×3,&nbsp;stride=1,&nbsp;type=float32,&nbsp;activation=leaky&nbsp;relu</td>
                </tr>
                <tr class="arch-table">
                    <td>Convolution</td>
                    <td>&#8680;&nbsp;4×4×256</td>
                    <td>size=1×1,&nbsp;stride=1,&nbsp;type=float32,&nbsp;activation=leaky&nbsp;relu</td>
                </tr>
                <tr class="arch-table">
                    <td>Convolution</td>
                    <td>&#8680;&nbsp;4×4×512</td>
                    <td>size=3×3,&nbsp;stride=1,&nbsp;type=float32,&nbsp;activation=leaky&nbsp;relu</td>
                </tr>
                <tr class="arch-table">
                    <td>Convolution</td>
                    <td>&#8680;&nbsp;4×4×256</td>
                    <td>size=1×1,&nbsp;stride=1,&nbsp;type=float32,&nbsp;activation=leaky&nbsp;relu</td>
                </tr>
                <tr class="arch-table">
                    <td>Convolution</td>
                    <td>&#8680;&nbsp;4×4×512</td>
                    <td>size=3×3,&nbsp;stride=1,&nbsp;type=float32,&nbsp;activation=leaky&nbsp;relu</td>
                </tr>
                <tr class="arch-table">
                    <td>Pooling</td>
                    <td>&#8680;&nbsp;2×2×512</td>
                    <td>size=2×2,&nbsp;stride=2,&nbsp;operation=max</td>
                </tr>
                <tr class="arch-table">
                    <td>Convolution</td>
                    <td>&#8680;&nbsp;2×2×1000</td>
                    <td>size=1×1,&nbsp;stride=1,&nbsp;type=float32,&nbsp;activation=leaky&nbsp;relu</td>
                </tr>
                <tr class="arch-table">
                    <td>Pooling</td>
                    <td>&#8680;&nbsp;1×1×1000</td>
                    <td>size=2×2,&nbsp;stride=1,&nbsp;operation=average</td>
                </tr>
                <tr class="arch-table">
                    <td>Softmax</td>
                    <td>&#8680;&nbsp;1×1×1000</td>
                    <td></td>
                </tr>
            </table>
        </td>
    </tr>
    <tr>
        <td> Output </td>
        <td colspan="3"> <a href="https://github.com/Microsoft/ELL-models/raw/master/models/ILSVRC2012/categories.txt">ILSVRC2012 1000 classes</a> </td>
    </tr>
    <tr>
        <td> Notes </td>
        <td colspan="3"> Trained by Juan Lema using CNTK 2.3.1 </td>
    </tr>
</table>

