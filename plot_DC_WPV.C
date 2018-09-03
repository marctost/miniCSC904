#include "snippet.C"

int graph_section(TString which_chamber, PlotterLines irr_0, PlotterLines irr_1, PlotterLines irr_2, PlotterLines irr_3, PlotterLines irr_4, PlotterLines irr_5, PlotterLines irr_6, PlotterLines irr_7, PlotterLines irr_8, PlotterLines irr_9, PlotterLines irr_10, PlotterLines ref_0, PlotterLines ref_1, PlotterLines ref_2, PlotterLines ref_3, PlotterLines ref_4, PlotterLines ref_5, PlotterLines ref_6, PlotterLines ref_7, PlotterLines ref_8, PlotterLines ref_9, PlotterLines ref_10);

TGraph* make_graph(TString which_chamber, int i, PlotterLines run_0, PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10);

TGraph* format_me(TGraph* graph, Color_t color);

void plot_DC_WPV(TString which_chamber) {
    ExcelSheet test(which_chamber+"/"+"analysis_page_darkCurrent.csv");
   
    //PlotterLines constructor args --
    //1st arg: excel spreadsheet
    //2nd arg: starting row (counts from 0)
    //3rd arg: ending row (counts from 0)
    //4th arg: column index (counts from 0)
    //5th arg: number of columns
    
    PlotterLines irr_0(test, 3, 10, 0, 2);
    PlotterLines irr_1(test, 3, 10, 5, 2);
    PlotterLines irr_2(test, 3, 10, 10, 2);
    PlotterLines irr_3(test, 3, 10, 15, 2);
    PlotterLines irr_4(test, 3, 10, 20, 2);
    PlotterLines irr_5(test, 3, 10, 25, 2);
    PlotterLines irr_6(test, 3, 10, 30, 2);
    PlotterLines irr_7(test, 3, 10, 35, 2);
    PlotterLines irr_8(test, 3, 10, 40, 2);
    PlotterLines irr_9(test, 3, 10, 45, 2);
    PlotterLines irr_10(test, 3, 10, 50, 2);
    
    PlotterLines ref_0(test, 3, 6, 2, 2);
    PlotterLines ref_1(test, 3, 6, 7, 2);
    PlotterLines ref_2(test, 3, 6, 12, 2);
    PlotterLines ref_3(test, 3, 6, 17, 2);
    PlotterLines ref_4(test, 3, 6, 22, 2);
    PlotterLines ref_5(test, 3, 6, 27, 2);
    PlotterLines ref_6(test, 3, 6, 32, 2);
    PlotterLines ref_7(test, 3, 6, 37, 2);
    PlotterLines ref_8(test, 3, 6, 42, 2);
    PlotterLines ref_9(test, 3, 6, 47, 2);
    PlotterLines ref_10(test, 3, 6, 52, 2);
    
    graph_section(which_chamber, irr_0, irr_1, irr_2, irr_3, irr_4, irr_5, irr_6, irr_7, irr_8, irr_9, irr_10, ref_0, ref_1, ref_2, ref_3, ref_4, ref_5, ref_6, ref_7, ref_8, ref_9, ref_10);
}

// Makes the graphs
TGraph* make_graph(TString which_chamber, int i, PlotterLines run_0, PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10){
    TGraph *graph = new TGraph(6); //argument is the number of runs/points on the graph for each data series
    
    std::vector<double> chamberDose;
    if (which_chamber.Contains("chamber5")){
        chamberDose = {0, 53, 95, 121, 149, 180, 209., 0., 0., 0., 0.};
    }
    else if (which_chamber.Contains("chamber4")){
        chamberDose = {0., 17., 26., 68., 123., 157., 0., 0., 0., 0., 0.};
    }
    
    //first argument is point number
    //second number is the dose (x-axis)
    //last number is the current at 3.6kV
    //argument of "at" corresponds to the row within
    graph->SetPoint(0, chamberDose[0], run_0.lines[1].at(i));
    graph->SetPoint(1, chamberDose[1], run_1.lines[1].at(i));
    graph->SetPoint(2, chamberDose[2], run_2.lines[1].at(i));
    graph->SetPoint(3, chamberDose[3], run_3.lines[1].at(i));
    graph->SetPoint(4, chamberDose[4], run_4.lines[1].at(i));
    graph->SetPoint(5, chamberDose[5], run_5.lines[1].at(i));
    //graph->SetPoint(5, chamberDose[6], run_6.lines[1].at(i));
    //graph->SetPoint(5, chamberDose[7], run_7.lines[1].at(i));
    //graph->SetPoint(5, chamberDose[8], run_8.lines[1].at(i));
    //graph->SetPoint(5, chamberDose[9], run_9.lines[1].at(i));
    //graph->SetPoint(5, chamberDose[10], run_10.lines[1].at(i));
    
    return graph;
}

// Sets the marker style and coloring for each graph
TGraph* format_me(TGraph* graph, Color_t color){
    graph->SetLineColor(color);
    graph->SetMarkerStyle(20);
    graph->SetMarkerSize(0.8);
    graph->SetMarkerColor(color);
    graph->SetLineWidth(2.0);
    
    return graph;
}

int graph_section(TString which_chamber, PlotterLines irr_0, PlotterLines irr_1, PlotterLines irr_2, PlotterLines irr_3, PlotterLines irr_4, PlotterLines irr_5, PlotterLines irr_6, PlotterLines irr_7, PlotterLines irr_8, PlotterLines irr_9, PlotterLines irr_10, PlotterLines ref_0, PlotterLines ref_1, PlotterLines ref_2, PlotterLines ref_3, PlotterLines ref_4, PlotterLines ref_5, PlotterLines ref_6, PlotterLines ref_7, PlotterLines ref_8, PlotterLines ref_9, PlotterLines ref_10){
    
    Color_t colors[] = {kBlue-10, kBlue-7, kBlue, kBlue+2, kAzure+4, kAzure+1, kRed, kRed+3, kRed-6, kOrange-3, kRed-3, kOrange+4, kPink, kGreen};
    
    //Just some styling stuff
    gROOT->SetBatch(true);
    gStyle->SetOptStat(2210);
    //    gStyle->SetTitleAlign(13);
    
    //References for margin, canvas and legend
    int H = 800;
    int W = H;
    float T = 0.08*H;
    float B = 0.12*H;
    float L = 0.12*W;
    float R = 0.04*W;
    float x1_l = 0.48;
    float y1_l = 0.90;
    float dx_l = 0.30;
    float dy_l = 0.30;
    float x0_l = x1_l-dx_l;
    float y0_l = y1_l-dy_l;
    
    //make the canvas, set its properties
    TCanvas *canvas = new TCanvas("c2","c2",50,50,W,H);
    canvas->SetFillColor(0);
    canvas->SetBorderMode(0);
    canvas->SetFrameFillStyle(0);
    canvas->SetFrameBorderMode(0);
    canvas->SetLeftMargin( L/W );
    canvas->SetRightMargin( R/W );
    canvas->SetTopMargin( T/H );
    canvas->SetBottomMargin( B/H );
    canvas->cd();
    
    //the legend happens
    TLegend *legend = new TLegend(x0_l,y0_l,x1_l,y1_l,"","brNDC");
    legend->SetBorderSize(1);
    
    // This function takes the line (which has been correctly sized), and then loops through and returns graphs for the corresponding wire pair
    //first argument is the row number, which corresponds to the row within the Plotterlines block where the 3.6 kV value is
    TGraph* graph_DC_irr = make_graph(which_chamber, 4, irr_0, irr_1, irr_2, irr_3, irr_4, irr_5, irr_6, irr_7, irr_8, irr_9, irr_10);
    TGraph* graph_DC_ref = make_graph(which_chamber, 2, ref_0, ref_1, ref_2, ref_3, ref_4, ref_5, ref_6, ref_7, ref_8, ref_9, ref_10);
    
    //Run the plots through the formater, select the desired colors from the list at beginning of function
    TGraph* fin_graph_DC_irr = format_me(graph_DC_irr, colors[9]);
    TGraph* fin_graph_DC_ref = format_me(graph_DC_ref, colors[5]);
    
    // Label the legend by hand
    legend->AddEntry(fin_graph_DC_irr, "Irradiated Layer");
    legend->AddEntry(fin_graph_DC_ref, "Reference Layer");
    
    // Make a multigraph to put all the stuff into and draw all at once.
    TMultiGraph *mg = new TMultiGraph();
    mg->Add(fin_graph_DC_irr);
    mg->Add(fin_graph_DC_ref);
    
    //    canvas->SetLogy();
    
    // title
    mg->SetTitle("Dark Current at 3.6 kV");
    
    mg->Draw("ALP");
    
    
    //  label axis
    mg->GetXaxis()->SetTitle("Accumulated charge (mC/cm)");
    mg->GetYaxis()->SetTitle("Current [pA]");
    if (which_chamber.Contains("chamber5")){
        mg->GetYaxis()->SetRangeUser(0., 1200.);
    }
    else if (which_chamber.Contains("chamber4")){
        mg->GetYaxis()->SetRangeUser(0., 650.);
    }
    else{
        mg->GetYaxis()->SetRangeUser(0., 1000.);
    }
    legend->Draw("SAME");
    
    // Locate where it goes and gets saved
    system("mkdir -p "+which_chamber+"/"+"Plots/");
    TString saveWhere = which_chamber+"/"+"Plots/darkcurrent_WPV.pdf";
    canvas->Update();
    canvas->SaveAs(saveWhere);
    delete canvas;
    
    return 0;
}

