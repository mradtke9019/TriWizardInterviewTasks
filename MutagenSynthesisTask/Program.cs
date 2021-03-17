using System;
using Mutagen;
using Mutagen.Bethesda.Skyrim;
using System.Linq;
using Mutagen.Bethesda;

namespace MutagenSynthesisTask
{
    class Program
    {
        static void Main(string[] args)
        {
            Testing();
            GetAllStatics();
            //ClearAllNavMeshes(); Dont call this, you will break your skyrim
        }

        public static void Testing()
        {
            using var state = GameEnvironment.Typical.Skyrim(SkyrimRelease.SkyrimSE);

            var skyrimCells = state.LoadOrder.PriorityOrder.Cell().WinningContextOverrides(state.LinkCache).Where(x => x.ModKey.FileName == "Skyrim.esm").ToList();
            var firstCell = state.LoadOrder.PriorityOrder.Cell().WinningContextOverrides(state.LinkCache).First(x => x.ModKey.FileName == "Skyrim.esm");


            var cells = state.LoadOrder.PriorityOrder.Cell().WinningContextOverrides(state.LinkCache).ToList();
            var cell = cells.First(x => x.Record.EditorID == "OLDBluePalaceWing01");

            var persistent = cell.Record.Persistent.ToList();
            var temporary = cell.Record.Temporary.ToList();

            //foreach(var p in persistent)
            //{
            //Console.WriteLine(string.Format("{0:X}", p.FormKey.ID) +  " " + p.EditorID);
            //}
            foreach (var t in temporary)
            {
                Console.WriteLine(string.Format("{0:X}", t.FormKey.ID) + " " + t.EditorID);
            }
        }

        public static void GetAllStatics(string cellEditorId = "OLDBluePalaceWing01")
        {
            using var state = GameEnvironment.Typical.Skyrim(SkyrimRelease.SkyrimSE);

            var cells = state.LoadOrder.PriorityOrder.Cell().WinningContextOverrides(state.LinkCache).ToList();
            var cell = cells.First(x => x.Record.EditorID == cellEditorId);

            var temporary = cell.Record.Temporary.ToList();

            foreach (var t in temporary)
            {
                Console.WriteLine(string.Format("{0:X}", t.FormKey.ID) + " " + t.EditorID);
            }
        }

        public static void ClearAllNavMeshes()
        {
            using var state = GameEnvironment.Typical.Skyrim(SkyrimRelease.SkyrimSE);
            foreach (var navContext in state.LoadOrder.PriorityOrder.ANavigationMesh().WinningContextOverrides(state.LinkCache))
            {
                var navMesh = navContext.Record;
                switch (navMesh)
                {
                    case ICellNavigationMeshGetter cellNavGetter:
                        CellNavigationMesh cellNav = (CellNavigationMesh)navContext;
                        // Clear the triangles if they exist?
                        cellNav.Data?.Triangles.Clear();
                        break;
                    case IWorldspaceNavigationMeshGetter worldNav:
                        // some code            
                        break;
                    default:
                        throw new NotImplementedException();
                }
            }
        }
    }
}
