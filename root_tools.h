
#ifndef root_tools_h
#define root_tools_h


TCanvas* make_canvas(){
    int H = 800;
    int W = H;
    float T = 0.08*H;
    float B = 0.12*H;
    float L = 0.12*W;
    float R = 0.04*W;
    
    TCanvas *canvas = new TCanvas("c2","c2",50,50,W,H);
    canvas->SetFillColor(0);
    canvas->SetBorderMode(0);
    canvas->SetFrameFillStyle(0);
    canvas->SetFrameBorderMode(0);
    canvas->SetLeftMargin( L/W );
    canvas->SetRightMargin( R/W );
    canvas->SetTopMargin( T/H );
    canvas->SetBottomMargin( B/H );
    
    return canvas;
}


TLegend* make_legend(){
    float x1_l = 0.48;
    float y1_l = 0.90;
    float dx_l = 0.30;
    float dy_l = 0.30;
    float x0_l = x1_l-dx_l;
    float y0_l = y1_l-dy_l;
    TLegend *legend = new TLegend(x0_l,y0_l,x1_l,y1_l,"","brNDC");
    legend->SetBorderSize(1);
    
    return legend;
}



#endif /* root_tools_h */
