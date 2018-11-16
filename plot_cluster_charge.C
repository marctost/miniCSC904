#include "snippet.C"

int graph_section(TString which_chamber, string filename, string norm_or_no, PlotterLines hole_num, PlotterLines run_0,PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10);
TGraph* make_graph(string norm_or_no, int i, PlotterLines run_0, PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10);
float  _val_ref(PlotterLines run);
TGraph* format_me(TGraph* graph, Color_t color);

void plot_cluster_charge(TString which_chamber, string which_plot, string norm_or_no) {
    ExcelSheet test(which_chamber+"/"+"analysis_page_cluster.csv");
    
    //PlotterLines constructor args --
    //1st arg: excel spreadsheet
    //2nd arg: starting row (counts from 0)
    //3rd arg: ending row (counts from 0)
    //4th arg: column index (counts from 0)
    //5th arg: number of adjacent columns(?)
    
    PlotterLines hole_num(test, 2, 14, 0, 1);
    PlotterLines run_0(test, 2, 14, 1, 1);
    PlotterLines run_1(test, 2, 14, 2, 1);
    PlotterLines run_2(test, 2, 14, 3, 1);
    PlotterLines run_3(test, 2, 14, 4, 1);
    PlotterLines run_4(test, 2, 14, 5, 1);
    PlotterLines run_5(test, 2, 14, 6, 1);
    PlotterLines run_6(test, 2, 14, 7, 1);
    PlotterLines run_7(test, 2, 14, 8, 1);
    PlotterLines run_8(test, 2, 14, 9, 1);
    PlotterLines run_9(test, 2, 14, 10, 1);
    PlotterLines run_10(test, 2, 14, 11, 1);
    
    graph_section(which_chamber, which_plot, norm_or_no, hole_num, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
}

//float Get_average_val_ref(PlotterLines run){
//    float divide=2;
//    float tot=0;
//    for (int i=10;i<12;i++){
//        if (run.lines[0].at(i)==0){
//            divide=divide-1;
//            continue;
//        }
//        tot = tot+run.lines[0].at(i);
//    }
//    return tot/divide;
//}


TGraph* make_graph(TString which_chamber, string norm_or_no, int i, PlotterLines run_0, PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10){
    
    int numRuns = 6;
    
    std::vector<double> chamberDose;
    int refNorm;
    int irrNorm;
    if (which_chamber.Contains("chamber5")){
        chamberDose = {0., 53., 95., 121., 149., 180., 209., 235., 0., 0., 0.};
        refNorm = 11; //ref(3,1)
        irrNorm = 5; //irr(3,1)
    }
    else if (which_chamber.Contains("chamber4")){
        chamberDose = {0., 26., 68., 123., 157., 188., 0., 0., 0., 0.};
        refNorm = 10; //ref(2,2)
        irrNorm = 4; //irr(2,2)
    }
    
    TGraph *graph = new TGraph(numRuns);
    // Note the the first number is the "point number" and will always be 0-11,
    // the second number the accumlated charge, and the last number is the value
    if (norm_or_no=="ref"){
        graph->SetPoint(0, chamberDose[0], run_0.lines[0].at(i)/run_0.lines[0].at(refNorm));
        graph->SetPoint(1, chamberDose[1], run_1.lines[0].at(i)/run_1.lines[0].at(refNorm));
        graph->SetPoint(2, chamberDose[2], run_2.lines[0].at(i)/run_2.lines[0].at(refNorm));
        graph->SetPoint(3, chamberDose[3], run_3.lines[0].at(i)/run_3.lines[0].at(refNorm));
        graph->SetPoint(4, chamberDose[4], run_4.lines[0].at(i)/run_4.lines[0].at(refNorm));
        graph->SetPoint(5, chamberDose[5], run_5.lines[0].at(i)/run_5.lines[0].at(refNorm));
//        graph->SetPoint(6, chamberDose[6], run_6.lines[0].at(i)/run_6.lines[0].at(refNorm));
//        graph->SetPoint(7, chamberDose[7], run_7.lines[0].at(i)/run_7.lines[0].at(refNorm));
        //graph->SetPoint(8, chamberDose[8], run_8.lines[0].at(i)/run_8.lines[0].at(refNorm));
        //graph->SetPoint(9, chamberDose[9], run_9.lines[0].at(i)/run_9.lines[0].at(refNorm));
        //graph->SetPoint(10, chamberDose[10], run_10.lines[0].at(i)/run_10.lines[0].at(refNorm));
    }
    else if (norm_or_no=="irr"){
        graph->SetPoint(0, chamberDose[0], run_0.lines[0].at(i)/run_0.lines[0].at(irrNorm));
        graph->SetPoint(1, chamberDose[1], run_1.lines[0].at(i)/run_1.lines[0].at(irrNorm));
        graph->SetPoint(2, chamberDose[2], run_2.lines[0].at(i)/run_2.lines[0].at(irrNorm));
        graph->SetPoint(3, chamberDose[3], run_3.lines[0].at(i)/run_3.lines[0].at(irrNorm));
        graph->SetPoint(4, chamberDose[4], run_4.lines[0].at(i)/run_4.lines[0].at(irrNorm));
        graph->SetPoint(5, chamberDose[5], run_5.lines[0].at(i)/run_5.lines[0].at(irrNorm));
//        graph->SetPoint(6, chamberDose[6], run_6.lines[0].at(i)/run_6.lines[0].at(irrNorm));
//        graph->SetPoint(7, chamberDose[7], run_7.lines[0].at(i)/run_7.lines[0].at(irrNorm));
        //graph->SetPoint(8, chamberDose[8], run_8.lines[0].at(i)/run_8.lines[0].at(irrNorm));
        //graph->SetPoint(9, chamberDose[9], run_9.lines[0].at(i)/run_9.lines[0].at(irrNorm));
        //graph->SetPoint(10, chamberDose[10], run_10.lines[0].at(i)/run_10.lines[0].at(irrNorm));
    }
    else{
        graph->SetPoint(0, chamberDose[0], run_0.lines[0].at(i));
        graph->SetPoint(1, chamberDose[1], run_1.lines[0].at(i));
        graph->SetPoint(2, chamberDose[2], run_2.lines[0].at(i));
        graph->SetPoint(3, chamberDose[3], run_3.lines[0].at(i));
        graph->SetPoint(4, chamberDose[4], run_4.lines[0].at(i));
        graph->SetPoint(5, chamberDose[5], run_5.lines[0].at(i));
//        graph->SetPoint(6, chamberDose[6], run_6.lines[0].at(i));
//        graph->SetPoint(7, chamberDose[7], run_7.lines[0].at(i));
        //graph->SetPoint(8, chamberDose[8], run_8.lines[0].at(i));
        //graph->SetPoint(9, chamberDose[9], run_9.lines[0].at(i));
        //graph->SetPoint(10, chamberDose[10], run_10.lines[0].at(i));
    }
    return graph;
}

TGraph* format_me(TGraph* graph, Color_t color){
    graph->SetLineColor(color);
    graph->SetMarkerStyle(20);
    graph->SetMarkerSize(0.8);
    graph->SetMarkerColor(color);
    graph->SetLineWidth(2.0);
    
    return graph;
}

int graph_section(TString which_chamber, string filename, string norm_or_no, PlotterLines hole_num, PlotterLines run_0, PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10){
	
    //Just some styling stuff
    gROOT->SetBatch(true);
    gStyle->SetOptStat(2210);
    gStyle->SetTitleAlign(23);
    
	//References for changing margins and the size of the canvas
	int H = 800;
	int W = H;
	float T = 0.08*H;
	float B = 0.12*H;
	float L = 0.12*W;
	float R = 0.04*W;
	float x1_l = 0.35;
	float y1_l = 0.35;
	float dx_l = 0.20;
	float dy_l = 0.20;
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
    
    Color_t colors[] = {kBlue-10, kBlue-7, kBlue, kBlue+2, kAzure+4, kAzure+1, kRed, kRed+3, kRed-6, kOrange-3, kRed-3, kOrange+4};
    
    TMultiGraph *mg = new TMultiGraph();
    
    if (which_chamber=="chamber5"){
        TGraph* graph_irr_2_1 = make_graph(which_chamber, norm_or_no, 3, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_irr_2_2 = make_graph(which_chamber, norm_or_no, 4, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_irr_3_1 = make_graph(which_chamber, norm_or_no, 5, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_irr_3_2 = make_graph(which_chamber, norm_or_no, 6, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_ref_2_2 = make_graph(which_chamber, norm_or_no, 10, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_ref_3_1 = make_graph(which_chamber, norm_or_no, 11, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        
        TGraph* fin_graph_irr_2_1 = format_me(graph_irr_2_1, colors[6]);
        TGraph* fin_graph_irr_2_2 = format_me(graph_irr_2_2, colors[7]);
        TGraph* fin_graph_irr_3_1 = format_me(graph_irr_3_1, colors[8]);
        TGraph* fin_graph_irr_3_2 = format_me(graph_irr_3_2, colors[9]);
        TGraph* fin_graph_ref_2_2 = format_me(graph_ref_2_2, colors[0]);
        TGraph* fin_graph_ref_3_1 = format_me(graph_ref_3_1, colors[1]);
        
        if (norm_or_no=="irr") {
            legend->AddEntry(fin_graph_irr_2_1, "Irr (2,1)");
            legend->AddEntry(fin_graph_irr_2_2, "Irr (2,2) (irr)");
            //        legend->AddEntry(fin_graph_irr_3_1, "Irr (3,1)");
            legend->AddEntry(fin_graph_irr_3_2, "Irr (3,2)");
        }
        else if (norm_or_no=="ref") {
            legend->AddEntry(fin_graph_irr_2_1, "Irr (2,1)");
            legend->AddEntry(fin_graph_irr_2_2, "Irr (2,2) (irr)");
            legend->AddEntry(fin_graph_irr_3_1, "Irr (3,1)");
            legend->AddEntry(fin_graph_irr_3_2, "Irr (3,2)");
            legend->AddEntry(fin_graph_ref_2_2, "Ref (2,2)");
            //        legend->AddEntry(fin_graph_ref_3_1, "Ref (3,1)");
        }
        else {
            legend->AddEntry(fin_graph_irr_2_1, "Irr (2,1)");
            legend->AddEntry(fin_graph_irr_2_2, "Irr (2,2) (irr)");
            legend->AddEntry(fin_graph_irr_3_1, "Irr (3,1)");
            legend->AddEntry(fin_graph_irr_3_2, "Irr (3,2)");
            legend->AddEntry(fin_graph_ref_2_2, "Ref (2,2)");
            legend->AddEntry(fin_graph_ref_3_1, "Ref (3,1)");
        }
        
        if (norm_or_no=="irr") {
            mg->Add(fin_graph_irr_2_1);
            mg->Add(fin_graph_irr_2_2);
            //        mg->Add(fin_graph_irr_3_1);
            mg->Add(fin_graph_irr_3_2);
        }
        else if (norm_or_no=="ref") {
            mg->Add(fin_graph_irr_2_1);
            mg->Add(fin_graph_irr_2_2);
            mg->Add(fin_graph_irr_3_1);
            mg->Add(fin_graph_irr_3_2);
            mg->Add(fin_graph_ref_2_2);
            //        mg->Add(fin_graph_ref_3_1);
        }
        else {
            mg->Add(fin_graph_irr_2_1);
            mg->Add(fin_graph_irr_2_2);
            mg->Add(fin_graph_irr_3_1);
            mg->Add(fin_graph_irr_3_2);
            mg->Add(fin_graph_ref_2_2);
            mg->Add(fin_graph_ref_3_1);
        }
    }
    
    else if (which_chamber=="chamber4"){
        TGraph* graph_irr_1_1 = make_graph(which_chamber, norm_or_no, 1, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_irr_1_2 = make_graph(which_chamber, norm_or_no, 2, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_irr_2_1 = make_graph(which_chamber, norm_or_no, 3, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_irr_2_2 = make_graph(which_chamber, norm_or_no, 4, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_irr_3_1 = make_graph(which_chamber, norm_or_no, 5, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_irr_3_2 = make_graph(which_chamber, norm_or_no, 6, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_ref_1_1 = make_graph(which_chamber, norm_or_no, 7, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_ref_1_2 = make_graph(which_chamber, norm_or_no, 8, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_ref_2_1 = make_graph(which_chamber, norm_or_no, 9, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_ref_2_2 = make_graph(which_chamber, norm_or_no, 10, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_ref_3_1 = make_graph(which_chamber, norm_or_no, 11, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        TGraph* graph_ref_3_2 = make_graph(which_chamber, norm_or_no, 12, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
        
        TGraph* fin_graph_irr_1_1 = format_me(graph_irr_1_1, colors[10]);
        TGraph* fin_graph_irr_1_2 = format_me(graph_irr_1_2, colors[11]);
        TGraph* fin_graph_irr_2_1 = format_me(graph_irr_2_1, colors[6]);
        TGraph* fin_graph_irr_2_2 = format_me(graph_irr_2_2, colors[7]);
        TGraph* fin_graph_irr_3_1 = format_me(graph_irr_3_1, colors[8]);
        TGraph* fin_graph_irr_3_2 = format_me(graph_irr_3_2, colors[9]);
        TGraph* fin_graph_ref_1_1 = format_me(graph_ref_1_1, colors[4]);
        TGraph* fin_graph_ref_1_2 = format_me(graph_ref_1_2, colors[5]);
        TGraph* fin_graph_ref_2_1 = format_me(graph_ref_2_1, colors[3]);
        TGraph* fin_graph_ref_2_2 = format_me(graph_ref_2_2, colors[0]);
        TGraph* fin_graph_ref_3_1 = format_me(graph_ref_3_1, colors[1]);
        TGraph* fin_graph_ref_3_2 = format_me(graph_ref_3_2, colors[2]);
        
        if (norm_or_no=="irr") {
            legend->AddEntry(fin_graph_irr_1_1, "Irr (1,1)");
            legend->AddEntry(fin_graph_irr_1_2, "Irr (1,2)");
            legend->AddEntry(fin_graph_irr_2_1, "Irr (2,1)");
            //            legend->AddEntry(fin_graph_irr_2_2, "Irr (2,2)"); //normalized to this one
            legend->AddEntry(fin_graph_irr_3_1, "Irr (3,1)");
            legend->AddEntry(fin_graph_irr_3_2, "Irr (3,2)");
        }
        else if (norm_or_no=="ref") {
            legend->AddEntry(fin_graph_irr_1_1, "Irr (1,1)");
            legend->AddEntry(fin_graph_irr_1_2, "Irr (1,2)");
            legend->AddEntry(fin_graph_irr_2_1, "Irr (2,1)");
            legend->AddEntry(fin_graph_irr_2_2, "Irr (2,2)");
            legend->AddEntry(fin_graph_irr_3_1, "Irr (3,1)");
            legend->AddEntry(fin_graph_irr_3_2, "Irr (3,2)");
            legend->AddEntry(fin_graph_ref_1_1, "Ref (1,1)");
            legend->AddEntry(fin_graph_ref_1_2, "Ref (1,2)");
            legend->AddEntry(fin_graph_ref_2_1, "Ref (2,1)");
            //            legend->AddEntry(fin_graph_ref_2_2, "Ref (2,2)"); //normalized to this one
            legend->AddEntry(fin_graph_ref_3_1, "Ref (3,1)");
            legend->AddEntry(fin_graph_ref_3_2, "Ref (3,2)");
        }
        else {
            legend->AddEntry(fin_graph_irr_1_1, "Irr (1,1)");
            legend->AddEntry(fin_graph_irr_1_2, "Irr (1,2)");
            legend->AddEntry(fin_graph_irr_2_1, "Irr (2,1)");
            legend->AddEntry(fin_graph_irr_2_2, "Irr (2,2)");
            legend->AddEntry(fin_graph_irr_3_1, "Irr (3,1)");
            legend->AddEntry(fin_graph_irr_3_2, "Irr (3,2)");
            legend->AddEntry(fin_graph_ref_1_1, "Ref (1,1)");
            legend->AddEntry(fin_graph_ref_1_2, "Ref (1,2)");
            legend->AddEntry(fin_graph_ref_2_2, "Ref (2,1)");
            legend->AddEntry(fin_graph_ref_2_2, "Ref (2,2)");
            legend->AddEntry(fin_graph_ref_3_1, "Ref (3,1)");
            legend->AddEntry(fin_graph_ref_3_2, "Ref (3,2)");
        }
        
        if (norm_or_no=="irr") {
            mg->Add(fin_graph_irr_1_1);
            mg->Add(fin_graph_irr_1_2);
            mg->Add(fin_graph_irr_2_1);
            //            mg->Add(fin_graph_irr_2_2); //normalized to this one
            mg->Add(fin_graph_irr_3_1);
            mg->Add(fin_graph_irr_3_2);
        }
        else if (norm_or_no=="ref") {
            mg->Add(fin_graph_irr_1_1);
            mg->Add(fin_graph_irr_1_2);
            mg->Add(fin_graph_irr_2_1);
            mg->Add(fin_graph_irr_2_2);
            mg->Add(fin_graph_irr_3_1);
            mg->Add(fin_graph_irr_3_2);
            mg->Add(fin_graph_ref_1_1);
            mg->Add(fin_graph_ref_1_2);
            mg->Add(fin_graph_ref_2_1);
            //            mg->Add(fin_graph_ref_2_2); //normalized to this one
            mg->Add(fin_graph_ref_3_1);
            mg->Add(fin_graph_ref_3_2);
        }
        else {
            mg->Add(fin_graph_irr_1_1);
            mg->Add(fin_graph_irr_1_2);
            mg->Add(fin_graph_irr_2_1);
            mg->Add(fin_graph_irr_2_2);
            mg->Add(fin_graph_irr_3_1);
            mg->Add(fin_graph_irr_3_2);
            mg->Add(fin_graph_ref_1_1);
            mg->Add(fin_graph_ref_1_2);
            mg->Add(fin_graph_ref_2_1);
            mg->Add(fin_graph_ref_2_2);
            mg->Add(fin_graph_ref_3_1);
            mg->Add(fin_graph_ref_3_2);
        }
    }
    
    TString title, label;
    label = "";
    if (which_chamber.Contains("chamber5")){
        if (norm_or_no=="ref"){
            label = ", Normalized to Ref. Layer (3,1)";
        }
        else if (norm_or_no=="irr"){
            label = ", Normalized to Irr. Layer (3,1)";
        }
    }
    else if (which_chamber.Contains("chamber4")){
        if (norm_or_no=="ref"){
            label = ", Normalized to Ref. Layer (2,2)";
        }
        else if (norm_or_no=="irr"){
            label = ", Normalized to Irr. Layer (2,2)";
        }
    }
    title = "Cluster Charge: Gaussian Mean"+label;
    mg->SetTitle(title);
    
    mg->Draw("ALP");

    mg->GetXaxis()->SetTitle("Accumulated charge (mC/cm)");
    if ( (norm_or_no=="ref") || (norm_or_no=="irr") ) {
        mg->GetYaxis()->SetTitle("Ratio");
    }
    else{
        mg->GetYaxis()->SetTitle("ADC Counts");
    }
    if (norm_or_no=="ref" or norm_or_no=="irr"){
        mg->GetYaxis()->SetRangeUser(0.5, 1.25);
    }
    else{
        mg->GetYaxis()->SetRangeUser(900, 1600);
    }

	legend->Draw("SAME");

    // Save plots
    system("mkdir -p "+which_chamber+"/"+"Plots/");
	TString saveWhere = which_chamber+"/"+"Plots/cluster_"+filename+norm_or_no+".pdf";
	canvas->Update();
//    canvas->SaveAs(saveWhere.c_str());
    canvas->SaveAs(saveWhere);
	canvas;

	return 0;
}
